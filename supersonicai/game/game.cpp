#include "game.h"

#include "supersonicai/python/helpers.h"

using namespace std;

namespace supersonicai
{
	namespace game
	{
		Game::Game() {
			_env = nullptr;

			_obs = nullptr;
			_reward = nullptr;
			_done = nullptr;
			_info = nullptr;

			one = PyLong_FromLong(1);
			zero = PyLong_FromLong(0);
		}

		Game::~Game() noexcept {
			Py_XDECREF(one);
			Py_XDECREF(zero);

			close();
		}

		bool Game::load(const std::string & gameName, const std::string & stageName) {
			PyObject * retro_make = supersonicai::python::retroMakeFunc();

			_env = supersonicai::python::call_func(
				retro_make,
				gameName,
				stageName);

			Py_DECREF(retro_make);

			return _env != nullptr;
		}

		void Game::reset() {
			Py_XDECREF(_obs);

			_obs = PyObject_CallMethod(_env, "reset", "()");
		}

		void Game::close() {
			//Py_XDECREF(_env);
			//
			//Py_XDECREF(_obs);
			//Py_XDECREF(_reward);
			//Py_XDECREF(_done);
			//Py_XDECREF(_info);
		}

		void Game::step(const Action & action) {
			// --- Create Button Presses ---
			const int nButtons = 12;

			PyObject * list = PyList_New(nButtons);

			for (int b = 0; b < nButtons; b++) {
				PyList_SetItem(list, b, (action[b] ? one : zero));
			}

			//PyObject_Print(list, stdout, Py_PRINT_RAW);
			//cout << endl;

			// --- Call _env.step() ---
			PyObject * ret = PyObject_CallMethod(_env, "step", "(O)", list);

			// --- Extract returned data ---
			Py_CLEAR(_obs);
			Py_CLEAR(_reward);
			Py_CLEAR(_done);
			Py_CLEAR(_info);

			_obs = PyTuple_GetItem(ret, 0);
			_reward = PyTuple_GetItem(ret, 1);
			_done = PyTuple_GetItem(ret, 2);
			_info = PyTuple_GetItem(ret, 3);

			Py_INCREF(_obs);
			Py_INCREF(_reward);
			Py_INCREF(_done);
			Py_INCREF(_info);

			//PyObject_Print(_info, stdout, Py_PRINT_RAW);

			Py_XDECREF(ret);

			return;
		}

		void Game::render() {
			cerr << "0x" << _env << ' ' << _env->ob_refcnt << " " << "0x" << _env->ob_type;
			cerr << endl << "<<<";
			PyObject_CallMethod(_env, "render", "()");
			cerr << ">>>" << endl;
		}

		python::Image Game::obs() const {
			return python::Image(_obs);
		}

		bool Game::done() const {

			return false;
		}

		int dictGetLong(PyObject * dict, const std::string & key) {
			PyObject * pyobj;
			int ret = -999;

			PyObject * pyKey = PyUnicode_FromString(key.c_str());

			if (PyDict_Contains(dict, pyKey)) {
				PyObject * pyVal = PyDict_GetItem(dict, pyKey);
				ret = PyLong_AsLong(pyVal);
			}

			return ret;
		}

		Info Game::info() const {
			Info ret;

			if (_info == nullptr) {
				cerr << "Error: info dict was null" << endl;
				return ret;
			}

			if (PyDict_Check(_info) == false) {
				cout << "Error:" << endl;
			}

			ret.act = dictGetLong(_info, "act");
			ret.zone = dictGetLong(_info, "zone");
			ret.level_end_bonus = dictGetLong(_info, "level_end_bonus");
			ret.rings = dictGetLong(_info, "rings");
			ret.score = dictGetLong(_info, "score");
			ret.lives = dictGetLong(_info, "lives");
			ret.x = dictGetLong(_info, "x");
			ret.y = dictGetLong(_info, "y");
			ret.screen_x_end = dictGetLong(_info, "screen_x_end");
			ret.screen_x = dictGetLong(_info, "screen_x");
			ret.screen_y = dictGetLong(_info, "screen_y");

			return ret;
		}
	} // namespace game
} // namespace supersonicai