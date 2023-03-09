#pragma once

#include "supersonicai/game/action.h"

namespace supersonicai
{
	namespace agents
	{
		class Base
		{
		public:
			virtual void load(const std::string & filename) = 0;
			
			virtual void save(const std::string & filename) = 0;

			virtual game::Action decide(/*cv::Mat, torch::Tensor*/) = 0;
		};
	} // namespace agents
} // namespace supersonicai