#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include <torch/nn/module.h>// for torch::nn::Module
//#include <torch/nn/options/linear.h>
#include <torch/nn/modules/linear.h>// for torch::nn::Linear
#include <torch/nn/modules/activation.h>// for torch::nn::Softmax

namespace supersonicai
{
	namespace networks
	{
		class Flatten : public torch::nn::Module
		{
		public:
			static torch::Tensor forward(torch::Tensor t) {
				int64_t nSamples = t.size(0);

				int64_t elements = 1;
				for (int i = 1; i < t.dim(); i++) {
					elements *= t.size(i);
				}

				return t.view({ nSamples, elements });
			}
		};

		class ActorCriticNetwork : public torch::nn::Module
		{
		public:
			ActorCriticNetwork();

			torch::Tensor forward(torch::Tensor x);

		private:
			torch::nn::Linear l1{ nullptr };
			torch::nn::Linear l2{ nullptr };
			torch::nn::Linear l3{ nullptr };
			torch::nn::Linear policy{ nullptr };
			torch::nn::Linear value{ nullptr };
			torch::nn::Softmax softmax;
		};
	} // namespace networks
} // namespace supersonicai