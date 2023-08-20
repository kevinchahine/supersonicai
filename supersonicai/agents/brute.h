#pragma once

#include "supersonicai/agents/base.h"
#include "supersonicai/game/action_sequence.h"

namespace supersonicai
{
	namespace agents
	{
		class Brute : public Base
		{
		public:
			virtual void load(const std::string & filename) override;

			virtual void save(const std::string & filename) const override;

			virtual game::Action decide(const cv::Mat & image) override;

		protected:
			game::ActionSequence actions;
			game::ActionSequence::const_iterator actionsIt;
		};
	} // namespace agents
} // namespace supersonicai