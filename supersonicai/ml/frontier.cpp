#include "supersonicai/ml/frontier.h"

using namespace std;

namespace supersonicai
{
	namespace ml
	{
		ml::State supersonicai::ml::Frontier::fetchTop() {
			ml::State & top = const_cast<ml::State &>(this->top());

			ml::State curr = move(top);
			
			this->pop();

			return curr;
		}
	} // namespace ml
} // namespace supersonicai
