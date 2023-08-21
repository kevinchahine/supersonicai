#pragma once

#include "supersonicai/game/action_sequence.h"
#include "supersonicai/rewards/reward_system.h"

#include <queue>
#include <set>

namespace supersonicai
{
	namespace ml
	{
		class State
		{
		public:
			bool operator<(const State & that) const { return this->reward < that.reward; }
			bool operator>(const State & that) const { return this->reward > that.reward; }
			bool operator==(const State & that) const { return this->reward == that.reward; }
			bool operator!=(const State & that) const { return this->reward != that.reward; }

		public:
			game::ActionSequence actions;
			rewards::reward_t reward;
		};
	} // namespace ml
} // namespace supersonicai