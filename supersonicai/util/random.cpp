#include "supersonicai/util/random.h"
#include "random.h"

using namespace std;

namespace supersonicai
{
	namespace util
	{
		default_random_engine g_dre(time(NULL));
	} // namespace util
} // namespace supersonicai
