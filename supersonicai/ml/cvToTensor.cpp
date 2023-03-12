#include "supersonicai/ml/cvToTensor.h"

#include <torch/torch.h>

using namespace std;

namespace supersonicai
{
	namespace ml
	{
		at::Tensor cvToTensor(cv::Mat img) {
			at::Tensor tensorImg = torch::from_blob(img.data, {1, img.rows, img.cols, 3}, at::kByte);

			return tensorImg;
		}
	} // namespace ml
} // namespace supersonicai