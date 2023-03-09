#pragma once

#include <iostream>

#define NPY_NO_DEPRECIATED_API NPY_1_7_API_VERSION
#include "Python.h"
#include "numpy/arrayobject.h"

#include <opencv2/core/mat.hpp>

#include "supersonicai/game/action.h"
#include "supersonicai/python/image.h"

namespace supersonicai
{
	namespace game
	{
		class Game
		{
		public:

			Game();
			Game(Game &&) noexcept = default;
			~Game() noexcept;
			Game & operator=(Game &&) noexcept = default;

			bool load(const std::string & gameName, const std::string & stageName);

			void reset();

			void close();

			void step(const Action & action);

			void render();

			python::Image getObs() const;

			int getReward() const;

			bool isDone() const;

			//void getInfo() const;

		private:
			PyObject * env;

			PyObject * obs;
			PyObject * reward;
			PyObject * done;
			PyObject * info;

			PyObject * one;
			PyObject * zero;
		};
	} // namespace game
} // namespace supersonicai
