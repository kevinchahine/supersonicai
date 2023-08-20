#pragma once

#include <boost/filesystem/path.hpp>

#include <opencv2/core/mat.hpp>

namespace supersonicai
{
	namespace dataset
	{
		namespace sprite
		{
			class Sprite
			{
			public:
				void load(const boost::filesystem::path & original, const boost::filesystem::path & segmentation);

			private:
				cv::Mat original;// comes from original image
				cv::Mat foreground;// comes from manual segmentation (label)
			};
		} // namespace sprite
	} // namespace dataset
} // namespace supersonicai