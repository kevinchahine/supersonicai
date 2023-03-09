#include "supersonicai/python/helpers.h"

#define NPY_NO_DEPRECIATED_API NPY_1_7_API_VERSION
#include "Python.h"
#include "numpy/arrayobject.h"

using namespace std;

namespace supersonicai
{
	namespace python
	{
		// --- Globals ---
		PyObject * retro_package = nullptr;

		int initialize() {
			Py_Initialize();

			import_array();

			retro_package = PyImport_ImportModule("retro");
		}

		PyObject * retroPackage() {
			return PyImport_ImportModule("retro");;
		}

		PyObject * retroMakeFunc() {
			PyObject * uName = PyUnicode_FromString("retro");
			PyObject * module = PyImport_Import(uName);// TODO: does this need to be decreffed
			Py_DECREF(uName);

			return PyObject_GetAttrString(module, "make");
		}

		PyObject * call_func(PyObject * func, const string & arg1, const string & arg2) {
			PyObject * args;
			PyObject * kwargs;
			PyObject * result = nullptr;

			PyGILState_STATE state = PyGILState_Ensure();

			if (!PyCallable_Check(func)) {
				cout << "call_func: expected a callable" << endl;
			}

			args = Py_BuildValue("(ss)", arg1.c_str(), arg2.c_str());
			kwargs = nullptr;

			result = PyObject_Call(func, args, kwargs);
			Py_DECREF(args);
			Py_XDECREF(kwargs);

			if (PyErr_Occurred()) {
				PyErr_Print();
			}

			PyGILState_Release(state);
			return result;
		}
		
		void finalize() {
			Py_DECREF(retro_package);

			Py_Finalize();
		}
	} // namespace python
} // namespace supersonicai