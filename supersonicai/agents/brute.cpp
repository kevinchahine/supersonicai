#include "supersonicai/agents/brute.h"

using namespace std;

namespace supersonicai
{
	namespace agents
	{
		void Brute::load(const string & filename) {
			actions.load(filename);

			actionsIt = actions.begin();
		}
		
		void Brute::save(const string & filename) const {
			actions.save(filename);
		}
		
		game::Action Brute::decide(const cv::Mat & image) {
			game::Action action;

			if (actionsIt != actions.end()) {
				action = *actionsIt;

				++actionsIt;
			}
			else {
				action.standStill();
				cout << "Last action reached" << endl;
			}

			return action;
		}
	} // namespace agents
} // namespace supersonicai