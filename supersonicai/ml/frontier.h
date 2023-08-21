#pragma once

#include <queue>
#include <set>

#include "supersonicai/game/game.h"
#include "supersonicai/ml/state.h"
#include "supersonicai/ml/trainer_base.h"
#include "supersonicai/rewards/reward_system.h"

namespace supersonicai
{
	namespace ml
	{
		class Frontier : public std::priority_queue<ml::State>
		{
		public:
			ml::State fetchTop();
		};
	} // namespace ml
} // namespace supersonicai