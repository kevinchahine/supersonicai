#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include "supersonicai/game/game.h"
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
	timer.expires_from_now(chrono::seconds(2));
	timer.resume();

	while (timer.is_not_expired()) {
		game.render();

		game.step(action);

		supersonicai::python::Image img = game.getObs();
	}

	cout << "Closing game...";
	game.close();
	cout << "Done";

	cout << "Finalizing Python...";
	supersonicai::python::finalize();
	cout << "Done" << endl;

	//cin.get();
	//this_thread::sleep_for(chrono::seconds(2));
	return 0;
}