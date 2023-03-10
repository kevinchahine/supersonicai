#include "supersonicai/vision/draw.h"

#include <opencv2/opencv.hpp>

#include <iostream>

namespace supersonicai
{
	namespace vision
	{
		void drawCrossHairs(cv::Mat & img) {
			cv::Point p1(img.size().width * 0.0, img.size().height / 2);
			cv::Point p2(img.size().width * 0.4, img.size().height / 2);
			cv::Point p3(img.size().width * 0.6, img.size().height / 2);
			cv::Point p4(img.size().width, img.size().height / 2);
	
			cv::Point p5(img.size().width / 2, img.size().height * 0.0);
			cv::Point p6(img.size().width / 2, img.size().height * 0.4);
			cv::Point p7(img.size().width / 2, img.size().height * 0.6);
			cv::Point p8(img.size().width / 2, img.size().height);

			cv::Scalar black(76, 255, 76);
			int thickness = 1;
			auto lineType = cv::FILLED;

			cv::line(img, p1, p2, black, thickness);
			cv::line(img, p3, p4, black, thickness);
			cv::line(img, p5, p6, black, thickness);
			cv::line(img, p7, p8, black, thickness);
		}
	} // namespace vision
} // namespace supersonicai