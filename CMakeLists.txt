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
)

set(NETWORKS
	
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

if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE "/MP")	# parallel compilation
endif()

target_link_libraries(${PROJECT_NAME} python38)
