#include "supersonicai/game/levels.h"
#include "supersonicai/util/random.h"

#include <random>

using namespace std;

namespace supersonicai
{
	namespace game
	{
		namespace levels
		{
			namespace sonic1
			{
				const Level level0("SonicTheHedgehog-Genesis", "GreenHillZone.Act1");
				const Level level1("SonicTheHedgehog-Genesis", "GreenHillZone.Act2");
				const Level level2("SonicTheHedgehog-Genesis", "GreenHillZone.Act3");
				const Level level3("SonicTheHedgehog-Genesis", "MarbleZone.Act1");
				const Level level4("SonicTheHedgehog-Genesis", "MarbleZone.Act2");
				const Level level5("SonicTheHedgehog-Genesis", "MarbleZone.Act3");
				const Level level6("SonicTheHedgehog-Genesis", "SpringYardZone.Act1");
				const Level level7("SonicTheHedgehog-Genesis", "SpringYardZone.Act2");
				const Level level8("SonicTheHedgehog-Genesis", "SpringYardZone.Act3");
				const Level level9("SonicTheHedgehog-Genesis", "LabyrinthZone.Act1");
				const Level level10("SonicTheHedgehog-Genesis", "LabyrinthZone.Act2");
				const Level level11("SonicTheHedgehog-Genesis", "LabyrinthZone.Act3");
				const Level level12("SonicTheHedgehog-Genesis", "StarLightZone.Act1");
				const Level level13("SonicTheHedgehog-Genesis", "StarLightZone.Act2");
				const Level level14("SonicTheHedgehog-Genesis", "StarLightZone.Act3");
				const Level level15("SonicTheHedgehog-Genesis", "ScrapBrainZone.Act1");
				const Level level16("SonicTheHedgehog-Genesis", "ScrapBrainZone.Act2");

				extern const std::array<Level, 17> levels = {
					level0,
					level1,
					level2,
					level3,
					level4,
					level5,
					level6,
					level7,
					level8,
					level9,
					level10,
					level11,
					level12,
					level13,
					level14,
					level15,
					level16,
				};

				const Level & selectRandom() {
					uniform_int_distribution<int> dist(0, levels.size() - 1);
				
					return levels.at(dist(util::g_dre));
				}
			} // namespace sonic1
		} // namespace levels
	} // namespace game
} // namespace supersonicai