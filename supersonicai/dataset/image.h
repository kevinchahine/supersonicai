#pragma once

#include <opencv2/core/mat.hpp>

#include "supersonicai/dataset/parallax/background.h"
#include "supersonicai/dataset/sprite/sprite.h"

namespace supersonicai
{
	namespace dataset
	{
		class Image : public cv::Mat
		{
		public:
			void overlay(const parallax::Background & background);

			void overlay(const sprite::Sprite & sprite);

		private:

		};
	} // namespace dataset
} // namespace supersonicai