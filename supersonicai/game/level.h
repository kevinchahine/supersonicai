#pragma once

#include <iostream>
#include <string>

namespace supersonicai
{
	namespace game
	{
		class Level
		{
		public:

			Level() = default;
			Level(const std::string & name, const std::string & stage) :
				_name(name),
				_stage(stage) {}
			Level(const Level &) = default;
			Level(Level &&) noexcept = default;
			~Level() noexcept = default;
			Level & operator=(const Level &) = default;
			Level & operator=(Level &&) noexcept = default;

			const std::string & name() const;

			const std::string & stage() const;

			friend std::ostream & operator<<(std::ostream & os, const Level & level) {
				os << level._name << ' ' << level._stage;

				return os;
			}

		private:
			std::string _name = "SonicTheHedgehog-Genesis";
			std::string _stage = "GreenHillZone.Act1";
		};
	} // namespace game
} // namespace supersonicai