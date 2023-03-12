#pragma once

#include <opencv2/core/mat.hpp>

#include <aten/Tensor.h>

namespace supersonicai
{
	namespace ml
	{
		at::Tensor cvToTensor(cv::Mat img);
	} // namespace ml
} // namespace supersonicai