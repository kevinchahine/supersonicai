#pragma once

#include "supersonicai/agents/base.h"

#include "supersonicai/networks/actor_critic_network.h"

namespace supersonicai
{
	namespace agents
	{
		class ActorCritic : public Base
		{
		public:
			virtual void load(const std::string & filename) override;

			virtual void save(const std::string & filename) override;

			virtual game::Action decide(const cv::Mat & image) override;

		private:
			networks::ActorCriticNetwork _network;
		};
	} // namespace agents
} // namespace supersonicai