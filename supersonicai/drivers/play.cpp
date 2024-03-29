
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
#include "supersonicai/ml/cvToTensor.h"

#include "supersonicai/networks/actor_critic_network.h"

#include "supersonicai/python/helpers.h"

#include "supersonicai/util/stopwatch.h"
#include "supersonicai/util/timer.h"

#include "supersonicai/vision/draw.h"
#include "supersonicai/vision/preprocessing.h"

using namespace std;
namespace ssa = supersonicai;

namespace supersonicai
{
	void play() {
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

		agent->load("brute_13.8207.txt");
		//agent->save("actions1.txt");

		game.load(level.name(), level.stage());
		game.reset();

		ssa::util::Timer timer;
		timer.expires_from_now(chrono::seconds(5));
		timer.resume();

		cv::Mat cvImg = game.obs().toCV();

		int frameCounter = 0;
		while (timer.is_not_expired()) {
			game.step(action);

			ssa::python::Image obs = game.obs();
			ssa::game::Info info = game.info();

			// --- Vision Pipeline ---

			cvImg = obs.toCV();

			if (cvImg.empty()) {
				std::cout << "Error: Empty image" << std::endl;
			}

			cv::cvtColor(cvImg, cvImg, cv::COLOR_RGB2BGR);
			cv::imshow("original", cvImg);

			ssa::vision::removeText(cvImg);
			cv::Mat img = ssa::vision::centerImageToSonic(cvImg, info);
			ssa::vision::downsample(img);

			cv::imshow("processed", img);

			cv::Mat big;
			cv::resize(img, big, cvImg.size() * 2);
			ssa::vision::drawCrossHairs(big);
			cv::imshow("big", big);

			cv::waitKey(1);

			action = agent->decide(img);
			cout << action << endl;
		} // end while()

		cout << "Closing game...";
		game.close();
		cout << "Done" << endl;
	}
} // namespace supersonicai