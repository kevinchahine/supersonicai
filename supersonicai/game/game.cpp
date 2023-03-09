#include "game.h"

#include "supersonicai/python/helpers.h"

using namespace std;

namespace supersonicai
{
	namespace game
	{
		Game::Game() {
			env = nullptr;

			obs = nullptr;
			reward = nullptr;
			done = nullptr;
			info = nullptr;

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

			env = supersonicai::python::call_func(
				retro_make, 
				gameName,
				stageName);

			Py_DECREF(retro_make);

			return env != nullptr;
		}

		void Game::reset() {
			Py_XDECREF(obs);

			obs = PyObject_CallMethod(env, "reset", "()");
		}

		void Game::close() {
			//Py_XDECREF(env);
			//
			//Py_XDECREF(obs);
			//Py_XDECREF(reward);
			//Py_XDECREF(done);
			//Py_XDECREF(info);
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

			// --- Call env.step() ---
			PyObject * ret = PyObject_CallMethod(env, "step", "(O)", list);

			// --- Extract returned data ---
			//Py_CLEAR(obs);
			//Py_CLEAR(reward);
			//Py_CLEAR(done);
			//Py_CLEAR(info);
			
			obs = PyTuple_GetItem(ret, 0);
			reward = PyTuple_GetItem(ret, 1);
			done = PyTuple_GetItem(ret, 2);
			info = PyTuple_GetItem(ret, 3);
			
			Py_XDECREF(ret);
		}

		void Game::render() {
			PyObject_CallMethod(env, "render", "()");
		}

		bool Game::isDone() const {

			return false;
		}
	} // namespace game
} // namespace supersonicai