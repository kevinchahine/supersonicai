#pragma once

#include <vector>

#include <opencv2/core/mat.hpp>

namespace supersonicai
{
	namespace dataset
	{
		namespace parallax
		{
			class Background
			{
			public:

			private:
				std::vector<cv::Mat> sections;
			};
		} // namespace parallax
	} // namespace dataset
} // namespace supersonicai