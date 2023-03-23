#pragma once

// ac method in python: https://github.com/pytorch/examples/blob/main/reinforcement_learning/actor_critic.py

#include <deque>

#include <aten/Tensor.h>

#include "supersonicai/ml/trainer_base.h"

namespace supersonicai
{
	namespace ml
	{
		class TensorPair
		{
		public:
			at::Tensor logProb;
			at::Tensor value;
		};

		class ActorCriticTrainer : public TrainerBase
		{
		public:
			virtual void trainOneEpoch() override;

		private:
			void selectAction(at::Tensor & image);

		private:


			std::deque<TensorPair> savedActions;
			std::deque<at::Tensor> rewards;
		};
	} // namespace ml
} // namespace supersonicai