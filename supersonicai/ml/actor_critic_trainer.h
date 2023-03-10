#pragma once

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