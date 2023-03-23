#include "supersonicai/networks/actor_critic_network.h"

using namespace std;

#include <torch/torch.h>

namespace supersonicai
{
	namespace networks
	{
		ActorCriticNetwork::ActorCriticNetwork() {
			l1 = register_module("l1", torch::nn::Linear(27'945, 1024));
			l2 = register_module("l2", torch::nn::Linear(1024, 1024));
			l3 = register_module("l3", torch::nn::Linear(1024, 256));
			policy = register_module("policy", torch::nn::Linear(256, 7));
			value = register_module("value", torch::nn::Linear(256, 1));
			softmax = register_module("softmax", torch::nn::Softmax(1));

			//l1->to(torch::kInt8);
			//l2->to(torch::kInt8);
			//l3->to(torch::kInt8);
			//l4->to(torch::kInt8);
		}

		ACTuple ActorCriticNetwork::forward(torch::Tensor x) {
			x = x.to(torch::kFloat32);

			// --- Network Body ---
			x = Flatten::forward(x);
			x = l1->forward(x);
			x = torch::relu(x);
			x = l2->forward(x);
			x = torch::relu(x);
			x = l3->forward(x);
			x = torch::relu(x);

			// --- Actor Critic Heads ---
			torch::Tensor policy_output = policy->forward(x);
			torch::Tensor value_output = value->forward(x);

			policy_output = softmax->forward(policy_output);// Calculate action probs

			/*return policy_output;*/
			return ACTuple{policy_output, value_output};
		}
	} // namespace networks
} // namespace supersonicai
