#pragma once

#include <iostream>

#include "Python.h"

namespace supersonicai
{
	namespace python
	{
		int initialize();

		PyObject * retroPackage();

		PyObject * retroMakeFunc();

		PyObject * call_func(PyObject * func, const std::string & arg1, const std::string & arg2);

		void finalize();
	} // namespace python
} // namespace supersonicai