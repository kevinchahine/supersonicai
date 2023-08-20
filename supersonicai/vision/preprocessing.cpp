#include "supersonicai/vision/preprocessing.h"

#include <opencv2/opencv.hpp>

using namespace std;

namespace supersonicai
{
	namespace vision
	{
		void removeText(cv::Mat & img) {
			cv::Rect2d score(17, 9, 105, 11);
			cv::Rect2d time(17, 25, 71, 11);
			cv::Rect2d rings(17, 41, 70, 11);
			cv::Rect2d lives(16, 200, 48, 16);

			cv::Scalar black(0, 0, 0);

			cv::rectangle(img, score, black, cv::FILLED);
			cv::rectangle(img, time, black, cv::FILLED);
			cv::rectangle(img, rings, black, cv::FILLED);
			cv::rectangle(img, lives, black, cv::FILLED);
		}

		cv::Mat centerImageToSonic(cv::Mat & img, const game::Info & info) {
			cv::Point center(info.x - info.screen_x, info.y - info.screen_y);

			return centerImage(img, center);
		}

		cv::Mat centerImage(cv::Mat & img, const cv::Point & center) {
			cv::Mat centered = cv::Mat::zeros(img.size() * 2, img.type());

			int x = img.size().width - center.x;
			int y = img.size().height - center.y;
			int w = img.size().width;
			int h = img.size().height;
			cv::Rect2d roi(x, y, w, h);

			// Trim region of interest to fit centered image
			cv::Rect2d centeredRect(cv::Point(0, 0), centered.size());

			roi = roi & centeredRect;// Intersection of centered and ROI

			cv::Rect2d imgRect(cv::Point(0, 0), roi.size());

			if (imgRect.empty() == false && roi.empty() == false) {
				img(imgRect).copyTo(centered(roi));
			}

			return centered;
		}
		
		void downsample(cv::Mat & img) {
			//cv::blur(img, img, cv::Size(4, 4));

			double ratio = 0.18;
			cv::resize(img, img, cv::Size(), ratio, ratio, cv::INTER_AREA);
		}
	} // namespace vision
} // namespace supersonicai