#include "supersonicai/vision/preprocessing.h"

#include <opencv2/highgui.hpp>// TODO: remove (debugging only)

using namespace std;

namespace supersonicai
{
	namespace vision
	{
		void removeText(cv::Mat & img) {

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

			img.copyTo(centered(roi));

			return centered;
		}
	} // namespace vision
} // namespace supersonicai