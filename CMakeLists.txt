cmake_minimum_required(VERSION 3.22)

SET(PROJECT_NAME supersonicai)
project(${PROJECT_NAME})

set(AGENTS 
	supersonicai/agents/actor_critic.cpp
	supersonicai/agents/actor_critic.h
	supersonicai/agents/base.cpp
	supersonicai/agents/base.h
	supersonicai/agents/random.cpp
	supersonicai/agents/random.h
	supersonicai/agents/replay.cpp
	supersonicai/agents/replay.h
)

set(GAME
	supersonicai/game/action.cpp
	supersonicai/game/action.h
	supersonicai/game/game.cpp
	supersonicai/game/game.h
	supersonicai/game/info.cpp
	supersonicai/game/info.h
	supersonicai/game/level.cpp
	supersonicai/game/level.h
	supersonicai/game/levels.cpp
	supersonicai/game/levels.h
)

set(ML
	supersonicai/ml/actor_critic_trainer.cpp
	supersonicai/ml/actor_critic_trainer.h
	supersonicai/ml/brute_trainer.cpp
	supersonicai/ml/brute_trainer.h
	supersonicai/ml/trainer_base.cpp
	supersonicai/ml/trainer_base.h
	supersonicai/ml/cvToTensor.cpp
	supersonicai/ml/cvToTensor.h
)

set(NETWORKS
	supersonicai/networks/actor_critic_network.cpp
	supersonicai/networks/actor_critic_network.h
)

set(NOTES
	supersonicai/notes/highleveldesign.txt
	supersonicai/notes/mvc.txt
	supersonicai/notes/python.txt
)

set(PYTHON 
	supersonicai/python/helpers.cpp
	supersonicai/python/helpers.h
	supersonicai/python/image.cpp
	supersonicai/python/image.h
)

set(UTIL
	supersonicai/util/stopwatch.cpp
	supersonicai/util/stopwatch.h
	supersonicai/util/timer.cpp
	supersonicai/util/timer.h
)

set(VIEWS
	supersonicai/views/base.cpp
	supersonicai/views/base.h
	supersonicai/views/image.cpp
	supersonicai/views/image.h
	supersonicai/views/none.cpp
	supersonicai/views/none.h
)

set(VISION
	supersonicai/vision/draw.cpp
	supersonicai/vision/draw.h
	supersonicai/vision/preprocessing.cpp
	supersonicai/vision/preprocessing.h
)

source_group(agents FILES ${AGENTS})
source_group(game FILES ${GAME})
source_group(ml FILES ${ML})
source_group(networks FILES ${NETWORKS})
source_group(notes FILES ${NOTES})
source_group(python FILES ${PYTHON})
source_group(util FILES ${UTIL})
source_group(views FILES ${VIEWS})
source_group(vision FILES ${VISION})

include_directories(.)

# Link Python
link_directories("C:\\Users\\kchah\\AppData\\Local\\Programs\\Python\\Python38\\libs")
include_directories("C:\\Users\\kchah\\AppData\\Local\\Programs\\Python\\Python38\\include")
include_directories("C:\\Users\\kchah\\AppData\\Local\\Programs\\Python\\Python38\\Lib\\site-packages\\numpy\\core\\include")

add_executable(${PROJECT_NAME}
	supersonicai/main.cpp
	.gitignore
	${AGENTS}
	${GAME}
	${ML}
	${NETWORKS}
	${NOTES}
	${PYTHON}
	${UTIL}
	${VIEWS}
	${VISION}
)

set(CMAKE_CXX_STANDARD 17)												# TODO: Do we need both?
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
message(STATUS "Compiler Version: ${CMAKE_CXX_COMPILER_VERSION} standard ${CMAKE_CXX_STANDARD}")
set(VS_STARTUP_PROJECT ${PROJECT_NAME})

# ----- Python -----

if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE "/MP")	# parallel compilation
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC python38)

# ----- Torch -----

set(CMAKE_CUDA_ARCHITECTURES 75)# all)
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

message(STATUS "\n----- Torch -----")

target_link_libraries(${PROJECT_NAME} PUBLIC
	"${TORCH_LIBRARIES}"
)

# Torch:
# The following code block is suggested to be used on Windows.
# According to https://github.com/pytorch/pytorch/issues/25457,
# the DLLs need to be copied to avoid memory errors.
if (MSVC)
	message(STATUS "--- :P d: :D ;)BX8==; MSVC :) ---")

	file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
	add_custom_command(
		TARGET ${PROJECT_NAME} 
		POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${TORCH_DLLS}
		$<TARGET_FILE_DIR:${PROJECT_NAME}>
	)
endif (MSVC)
