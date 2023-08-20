#pragma once

#include <array>
#include <iostream>
#include <queue>

#include "supersonicai/game/action.h"

namespace supersonicai
{
	namespace game
	{
		class ActionSequence : public std::deque<Action>
		{
		private:
			using super_t = std::deque<Action>;

		public:
			void load(const std::string & filename);

			void save(const std::string & filename) const;

			void push_back(const Action & action, size_t nFrames = 1);

		};
	} // namespace game
} // namespace supersonicai