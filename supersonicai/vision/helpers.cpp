#include "supersonicai/vision/helpers.h"

#include <iostream>

#include <opencv2/opencv.hpp>

namespace supersonicai
{
	namespace vision
	{
		void imshow(const std::string & windowName, python::Image & obs) {
			cv::Mat cvImg = obs.toCV();

			cv::cvtColor(cvImg, cvImg, cv::COLOR_RGB2BGR);
			cv::imshow(windowName, cvImg);
			cv::waitKey(1);
		}
	} // namespace vision
} // namespace supersonicai