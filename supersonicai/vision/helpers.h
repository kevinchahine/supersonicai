#pragma once

#include "supersonicai/python/image.h"

namespace supersonicai
{
	namespace vision
	{
		void imshow(const std::string & windowName, python::Image & obs);
	} // namespace vision
} // namespace supersonicai