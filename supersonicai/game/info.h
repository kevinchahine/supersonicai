#pragma once

#include <iostream>

namespace supersonicai
{
	namespace game
	{
		class Info
		{
		public:

			friend std::ostream & operator<<(std::ostream & os, const Info & _info) {
				os
					<< "act: " << _info.act << ", "
					<< "zone: " << _info.zone << ", "
					<< "level_end_bonus: " << _info.level_end_bonus << ", "
					<< "rings: " << _info.rings << ", "
					<< "score: " << _info.score << ", "
					<< "lives: " << _info.lives << ", "
					<< "x: " << _info.x << ", "
					<< "y: " << _info.y << ", "
					<< "screen_x_end: " << _info.screen_x_end << ", "
					<< "screen_x: " << _info.screen_x << ", "
					<< "screen_y: " << _info.screen_y;

				return os;
			}

		public:
			int act;
			int zone;
			int level_end_bonus;
			int rings;
			int score;
			int lives;
			int x;
			int y;
			int screen_x_end;
			int screen_x;
			int screen_y;
		};
	} // namespace game
} // namespace supersonicai