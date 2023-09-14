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

#include "supersonicai/drivers/play.h"
#include "supersonicai/drivers/train.h"

using namespace std;
namespace ssa = supersonicai;

int main(int argc, char ** argv) {
	cout 
		<< "======================" << endl
		<< "=== SUPER SONIC AI ===" << endl
		<< "======================" << endl;

	cout << "Initializing Python...";
	ssa::python::initialize();
	cout << "Done" << endl;

	//ssa::play();
	ssa::train();

	cv::destroyAllWindows();

	cout << "Finalizing Python...";
	ssa::python::finalize();
	cout << "Done" << endl;

	//cin.get();
	//this_thread::sleep_for(chrono::seconds(2));
	return 0;
}