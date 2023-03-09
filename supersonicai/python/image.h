#pragma once

#include <iostream>

#include "Python.h"
#include "numpy/arrayobject.h"

#include <opencv2/core/mat.hpp>

namespace supersonicai
{
	namespace python
	{
		class Image
		{
		public:
			Image(PyObject * img);
			Image(Image &&) noexcept = default;
			~Image() noexcept = default;
			Image & operator=(Image &&) noexcept = default;

			cv::Mat toCV();

			//torch::Tensor toTensor();

		private:

			PyArrayObject * npArray = nullptr;
		};
	} // namespace python
} // namespace supersonicai