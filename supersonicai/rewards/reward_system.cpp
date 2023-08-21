#pragma once

#include "supersonicai/rewards/reward_system.h"

using namespace std;

namespace supersonicai
{
	namespace rewards
	{
		void RewardSystem::update(const game::Info & info) {
			this->score = info.score;
			this->ringCount = info.rings;
			this->x = info.x;
			this->y = info.y;
		}

		reward_t RewardSystem::calcReward() const {
			reward_t reward = 1;

			reward += score * scoreReward;
			reward += ringCount * ringCountReward;
			reward += x * xReward;
			reward += y * yReward;

			return reward;
		}
	} // namespace rewards
} // namespace supersonicai