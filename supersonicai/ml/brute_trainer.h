#pragma once

#include <queue>
#include <set>

#include "supersonicai/game/game.h"
#include "supersonicai/ml/frontier.h"
#include "supersonicai/ml/state.h"
#include "supersonicai/ml/trainer_base.h"
#include "supersonicai/rewards/reward_system.h"

namespace supersonicai
{
	namespace ml
	{
		class BruteTrainer : public TrainerBase
		{
		public:
			virtual void initialize() override;
			
			virtual void trainOneEpoch() override;

		protected:
			ml::State branchFrom(const ml::State & currState, const game::Action & action);

		private:
			ml::Frontier frontier;

			game::Game game;
		};
	} // namespace ml
} // namespace supersonicai