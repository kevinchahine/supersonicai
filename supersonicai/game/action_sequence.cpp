#include "action_sequence.h"

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace supersonicai
{
	namespace game
	{
		void ActionSequence::load(const std::string & filename) {
			ifstream inFile(filename);

			this->clear();

			string line;

			while (getline(inFile, line)) {
				Action action;
				istringstream iss(line);

				iss >> action;

				this->push_back(action);
			}
		}

		void ActionSequence::save(const std::string & filename) const {
			ofstream out(filename);

			for (
				ActionSequence::const_iterator it = this->super_t::begin();
				it != this->super_t::end();
				++it) {
				Action action = *it;

				out << action << endl;
			}
		}

		void ActionSequence::push_back(const Action & action, size_t nFrames) {
			for (size_t n = 0; n < nFrames; n++) {
				this->super_t::push_back(action);
			}
		}
	} // namespace game
} // namespace supersonicai