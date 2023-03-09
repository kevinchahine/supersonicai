#pragma once

#include <iostream>

#include "image.h"

namespace supersonicai
{
	namespace python
	{
		Image::Image(PyObject * img) :
			npArray(reinterpret_cast<PyArrayObject *>(img)) {}

		cv::Mat Image::toCV() {
			// --- Extract Data ---

			// --- N Dimensions ---
			
			int nDims = PyArray_NDIM(npArray);
			if (nDims != 3) {
				throw std::runtime_error("number of dimensions does not equal 3");
			}

			// --- Shape ---

			npy_intp * shape = PyArray_SHAPE(npArray);
			int nRows = shape[0];
			int nCols = shape[1];
			int nChan = shape[2];

			cv::Size size(nCols, nRows);

			// --- Data Pointer ---

			uint8_t * data = reinterpret_cast<uint8_t *>(PyArray_DATA(npArray));

			// --- Create CV Mat ---

			cv::Mat cvImg = cv::Mat(size, CV_8UC3, data);

			return cvImg;
		}
	} // namespace python
} // namespace supersonicai