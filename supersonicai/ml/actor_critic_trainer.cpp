// source: https://github.com/Omegastick/pytorch-cpp-rl/

#include "supersonicai/ml/actor_critic_trainer.h"
#include "supersonicai/ml/cvToTensor.h"

#include "supersonicai/agents/actor_critic.h"

#include "supersonicai/distributions/categorical.h"

using namespace std;

namespace supersonicai
{
	namespace ml
	{
		void ActorCriticTrainer::trainOneEpoch() {

			// --- Select Action ---
		}

		void ActorCriticTrainer::selectAction(at::Tensor & image) {
			agents::ActorCritic * ptr = dynamic_cast<agents::ActorCritic*>(this->_agent);
			if (ptr == nullptr) {
				cout << "Error" << endl;
			}

			agents::ActorCritic & agent = *ptr;

			networks::ACTuple output = agent.network().forward(image);

			at::Tensor & probs = output.policy;
			at::Tensor & state_value = output.value;

			// Create a categorical distribution over the list of probabilities of actions
			distributions::Categorical m = distributions::Categorical(&probs, nullptr);

			// Sample an action using the distribution
			at::Tensor action = m.sample();

			// Save to action buffer 
			TensorPair tp{ m.log_prob(action), state_value };

			savedActions.push_back(tp);

			return ;
		}
	} // namespace ml
} // namespace supersonicai