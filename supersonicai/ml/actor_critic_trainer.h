#pragma once

// ac method in python: https://github.com/pytorch/examples/blob/main/reinforcement_learning/actor_critic.py

#include "supersonicai/ml/trainer_base.h"

namespace supersonicai
{
	namespace ml
	{
		class ActorCriticTrainer : public TrainerBase
		{
		public:
			virtual void trainOneEpoch() override;

		private:

		};
	} // namespace ml
} // namespace supersonicai