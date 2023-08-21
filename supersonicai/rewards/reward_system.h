#pragma once

#include "supersonicai/game/info.h"

namespace supersonicai
{
	namespace rewards
	{
		using reward_t = float;

		class RewardSystem {
		public:
			void update(const game::Info & info);

			reward_t calcReward() const;

		protected:
			reward_t score = 0;
			reward_t scoreReward = 100;

			reward_t x = 0;
			reward_t xReward = 1;

			reward_t y = 0;
			reward_t yReward = 0;

			reward_t ringCount = 0;
			reward_t ringCountReward = 0;
		};
	} // namespace rewards
} // namespace supersonicai