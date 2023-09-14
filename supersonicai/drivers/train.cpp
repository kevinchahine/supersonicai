
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "supersonicai/agents/actor_critic.h"
#include "supersonicai/agents/brute.h"
#include "supersonicai/agents/random.h"
#include "supersonicai/agents/agents.hpp"

#include "supersonicai/game/game.h"
#include "supersonicai/game/info.h"
#include "supersonicai/game/level.h"
#include "supersonicai/game/levels.h"

#include "supersonicai/ml/actor_critic_trainer.h"
#include "supersonicai/ml/brute_trainer.h"
#include "supersonicai/ml/cvToTensor.h"

#include "supersonicai/networks/actor_critic_network.h"

#include "supersonicai/python/helpers.h"

#include "supersonicai/util/stopwatch.h"
#include "supersonicai/util/timer.h"

#include "supersonicai/vision/draw.h"
#include "supersonicai/vision/preprocessing.h"
#include "train.h"

using namespace std;
namespace ssa = supersonicai;

namespace supersonicai
{
	void train() {
		ssa::game::Game game;

		ssa::game::Level level =
			//ssa::game::levels::sonic1::selectRandom();
			ssa::game::levels::sonic1::level0;

		ssa::game::Action action;
		action.reset();
		action.runRight();

		unique_ptr<ssa::agents::Base> agent =
			//make_unique<ssa::agents::ActorCritic>();
			make_unique<ssa::agents::Brute>();

		unique_ptr<ssa::ml::TrainerBase> trainer =
			//make_unique<ssa::ml::ActorCriticTrainer>();
			make_unique<ssa::ml::BruteTrainer>();

		trainer->initialize();

		ssa::util::Timer timer;
		timer.expires_from_now(chrono::seconds(60));
		timer.resume();

		while (timer.is_not_expired()) {
			trainer->trainOneEpoch();
		} // end while()

		cout << "Closing game...";
		game.close();
		cout << "Done" << endl;
	}
} // namespace supersonicai