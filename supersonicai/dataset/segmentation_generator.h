#pragma once

#include <iostream>
#include <filesystem>

namespace supersonicai
{
	namespace dataset
	{
		class SegmentationGenerator
		{
		public:

		private:
			std::filesystem::path _inputDir;
			std::filesystem::path _outputDir;
		};
	} // namespace dataset
} // namespace supersonicai