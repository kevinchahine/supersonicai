#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "supersonicai/game/game.h"
#include "supersonicai/game/info.h"
#include "supersonicai/game/level.h"
#include "supersonicai/game/levels.h"

#include "supersonicai/python/helpers.h"

#include "supersonicai/util/stopwatch.h"
#include "supersonicai/util/timer.h"

using namespace std;

int main(int argc, char ** argv) {
	cout 
		<< "======================" << endl
		<< "=== SUPER SONIC AI ===" << endl
		<< "======================" << endl;

	cout << "Initializing Python...";
	supersonicai::python::initialize();
	cout << "Done" << endl;

	supersonicai::game::Game game;

	supersonicai::game::Level level = supersonicai::game::levels::sonic1::level0;

	supersonicai::game::Action action;
	action.reset();
	action.pushRight();

	game.load(level.name(), level.stage());
	game.reset();

	supersonicai::util::Timer timer;
	timer.expires_from_now(chrono::seconds(1));
	timer.resume();

	cv::Mat cvImg = cv::Mat::zeros(cv::Size(340, 224), CV_8UC3);

	int frameCounter = 0;
	while (timer.is_not_expired()) {
		cout << "---1---" << endl;
		//game.render();
		cv::imshow("cv window", cvImg);
		cout << "---2---" << endl;

		frameCounter++;
		if (frameCounter < 200) {
		}
		else if (frameCounter < 430) {
			action.reset();
			action.pushDown();
		}
		else {
			action.reset();
			action.pushRight();
		}

		cout << frameCounter << endl;

		game.step(action);

		cout << "---3---" << endl;

		//supersonicai::python::Image obs = game.obs();
		//supersonicai::game::Info info = game.info();

		//cout << endl << info << endl << endl;
		cout << "---4---" << endl;

		//cvImg = obs.toCV();
		//cv::imshow("cv", cvImg);
		//cv::waitKey(10);
	}

	//cv::imwrite("img.png", cvImg);

	cv::destroyAllWindows();

	cout << "Closing game...";
	game.close();
	cout << "Done" << endl;

	cout << "Finalizing Python...";
	supersonicai::python::finalize();
	cout << "Done" << endl;

	//cin.get();
	//this_thread::sleep_for(chrono::seconds(2));
	return 0;
}