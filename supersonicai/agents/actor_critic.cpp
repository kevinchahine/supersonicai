#include "actor_critic.h"

#include "supersonicai/ml/cvToTensor.h"

using namespace std;

namespace supersonicai
{
	namespace agents
	{
		void ActorCritic::load(const std::string & filename) {}

		void ActorCritic::save(const std::string & filename) const {}
		
		game::Action ActorCritic::decide(const cv::Mat & image) {

			at::Tensor imgTensor = supersonicai::ml::cvToTensor(image);
			networks::ACTuple output = _network.forward(imgTensor);

			int index = output.policy.argmax().item<int>();
			
			//cout << index << '\t' ;
			return game::Action(index);
		}
	} // namespace agents
} // namespace supersonicai