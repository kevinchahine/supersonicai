#pragma once

#include "supersonicai/agents/base.h"

namespace supersonicai
{
	namespace agents
	{
		class ActorCritic : public Base
		{
		public:
			virtual void load(const std::string & filename) override;

			virtual void save(const std::string & filename) override;

			virtual game::Action decide(const cv::Mat * image) override;

		private:

		};
	} // namespace agents
} // namespace supersonicai