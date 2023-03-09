#pragma once

#include <iostream>
#include <chrono>

namespace supersonicai
{
	namespace util
	{
		class Timer
		{
		public:

			void pause();

			void resume();

			bool is_paused() const { return state == STATE::PAUSED; }

			bool is_resumed() const { return state == STATE::RESUMED; }

			bool is_expired() const;

			bool is_not_expired() const { return !is_expired(); }

			// Make sure to call resume() after this method
			void expires_from_now(const std::chrono::nanoseconds & duration);

			std::chrono::nanoseconds expires_from_now() const;

			void add_time(const std::chrono::nanoseconds & duration);

			friend std::ostream & operator<<(std::ostream & os, const Timer & timer) {
				using namespace std;

				auto expiry = timer.expires_from_now();

				auto mins = chrono::duration_cast<chrono::minutes>(expiry);

				auto secs = chrono::duration_cast<chrono::seconds>(expiry - mins);

				os << mins.count() << ":" << secs.count();

				return os;
			}
		protected:

			// Time at which the timer was last resumed
			std::chrono::high_resolution_clock::time_point lastResumed =
				std::chrono::high_resolution_clock::now();

			// Amount of time left in the timer at the time the timer was last resumed.
			// If the timer is paused then 
			std::chrono::nanoseconds expiry = std::chrono::nanoseconds(0);

			enum class STATE : bool
			{
				PAUSED,
				RESUMED
			} state = STATE::PAUSED;
		};
	} // namespace util
} // namespace supersonicai
