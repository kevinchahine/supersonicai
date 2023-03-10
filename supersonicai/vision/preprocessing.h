#pragma once

#include <iostream>

#include <opencv2/core/mat.hpp>

#include <supersonicai/game/info.h>

namespace supersonicai
{
	namespace vision
	{
		void removeText(cv::Mat & img);

		cv::Mat centerImageToSonic(cv::Mat & img, const game::Info & info);

		cv::Mat centerImage(cv::Mat & img, const cv::Point & center);

		void downsample(cv::Mat & img);
	} // namespace vision
} // namespace supersonicai