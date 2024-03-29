#pragma once

#include "supersonicai/agents/base.h"

namespace supersonicai
{
	namespace agents
	{
		class Random : public Base
		{
			virtual void load(const std::string & filename) override;

			virtual void save(const std::string & filename) const override;

			virtual game::Action decide(const cv::Mat & image) override;
		};
	} // namespace agents
} // namespace supersonicai