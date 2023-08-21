#pragma once

#include "supersonicai/agents/base.h"
#include "supersonicai/game/action_sequence.h"

namespace supersonicai
{
	namespace ml
	{
		// Epoch based trainer.
		class TrainerBase
		{
		public:
			virtual void initialize() = 0;

			virtual void trainOneEpoch() = 0;

		protected:
			// Agent to be trained.
			// Non-owning pointer. 
			// Don't delete
			agents::Base * _agent = nullptr;

			int epochNumber = 0;
		};
	} // namespace ml
} // namespace supersonicai