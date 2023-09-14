#include "supersonicai/ml/brute_trainer.h"

#include <opencv2/opencv.hpp>

#include "supersonicai/agents/brute.h"
#include "supersonicai/game/levels.h"
#include "supersonicai/rewards/reward_system.h"
#include "supersonicai/util/stopwatch.h"
#include "supersonicai/vision/helpers.h"

using namespace std;

namespace supersonicai
{
	namespace ml
	{
		void BruteTrainer::initialize() {
			// --- Frontier ---

			ml::State state;
			game::Action action;
			action.runRight();

			state.actions.push_back(action, 10);
			state.reward = 0;

			frontier.push(move(state));

			// --- Game ---
			game::Level level = 
				game::levels::sonic1::level0;

			game.load(level.name(), level.stage());
			game.reset();

			game.step(game::Action::StandStill());
		}

		void BruteTrainer::trainOneEpoch() {
			if (frontier.empty()) {
				cout << "Frontier is empty" << endl;
			}

			// --- 1.) Get current state ---
			ml::State curr = frontier.fetchTop();

			// --- 2.) Branch from this state ---
			frontier.push(branchFrom(curr, game::Action::StandStill()));
			frontier.push(branchFrom(curr, game::Action::RunRight()));
			frontier.push(branchFrom(curr, game::Action::RunLeft()));
			frontier.push(branchFrom(curr, game::Action::JumpRight()));
			frontier.push(branchFrom(curr, game::Action::Jump()));
			frontier.push(branchFrom(curr, game::Action::JumpLeft()));
			frontier.push(branchFrom(curr, game::Action::LookUp()));
			frontier.push(branchFrom(curr, game::Action::Crouch()));

			// TODO: i don't like this
			// --- 3.) Save the best so far ---
			const ml::State & best = frontier.top();
			stringstream ss;
			ss << "brute_" << best.reward << ".txt";
			best.actions.save(ss.str());
		}

		ml::State BruteTrainer::branchFrom(const ml::State & currState, const game::Action & action) {
			ml::State next = currState;// copy the current state

			next.actions.push_back(action, 40);

			// --- 2.) Reproduce current new state ---
			// We need to know what this state looks like
			game.reset();
			game.step(game::Action::StandStill());

			cout << "Simulating action sequence (size = " << next.actions.size() << ")" << endl;
			util::StopWatch simTime;
			simTime.resume();

			size_t frameCount = 0;
			const game::ActionSequence & actions = next.actions;
			for (const game::Action & action : actions) {
				///cout << "action: " << action << endl;
				game.step(action);

				python::Image obs = game.obs();
				game::Info info = game.info();
				
				frameCount++;
				if (frameCount % 10 == 0) {
					vision::imshow("Brute Trainer", obs);
				}
			}

			simTime.pause();

			// --- 3.) Analyze Outcome of ActionSequence ---
			rewards::RewardSystem rewardSystem;
			rewardSystem.update(game.info());

			next.reward = rewardSystem.calcReward();
			next.reward /= next.actions.size();
			cout 
				<< "Sim Time: " << simTime.elapsed().count() << '\t'
				<< "Reward for this state: " << next.reward 
				<< " action sequence length: " << next.actions.size() 
				<< endl;

			return next;
		}
	} // namespace ml
} // namespace supersonicai