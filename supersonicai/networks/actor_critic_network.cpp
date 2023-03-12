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
			l4 = register_module("l4", torch::nn::Linear(256, 7));
			smax = register_module("smax", torch::nn::Softmax(1));

			//l1->to(torch::kInt8);
			//l2->to(torch::kInt8);
			//l3->to(torch::kInt8);
			//l4->to(torch::kInt8);
		}

		torch::Tensor ActorCriticNetwork::forward(torch::Tensor x) {
			x = x.to(torch::kFloat32);

			x = Flatten::forward(x);
			x = l1->forward(x);
			x = torch::sigmoid(x);
			x = l2->forward(x);
			x = torch::sigmoid(x);
			x = l3->forward(x);
			x = torch::sigmoid(x);
			x = l4->forward(x);
			x = torch::sigmoid(x);
			x = smax->forward(x);

			return x;
		}
	} // namespace networks
} // namespace supersonicai
