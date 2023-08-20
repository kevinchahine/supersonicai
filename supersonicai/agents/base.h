#pragma once

#include "supersonicai/game/action.h"

#include <opencv2/core/mat.hpp>

namespace supersonicai
{
	namespace agents
	{
		class Base
		{
		public:
			virtual void load(const std::string & filename) = 0;
			
			virtual void save(const std::string & filename) const = 0;

			virtual game::Action decide(const cv::Mat & image) = 0;
		};
	} // namespace agents
} // namespace supersonicai