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
	# "supersonicai/python/"
)

set(VIEWS
	supersonicai/views/base.cpp
	supersonicai/views/base.h
	supersonicai/views/image.cpp
	supersonicai/views/image.h
	supersonicai/views/none.cpp
	supersonicai/views/none.h
)

source_group(agents FILES ${AGENTS})
source_group(ml FILES ${ML})
source_group(networks FILES ${NETWORKS})
source_group(notes FILES ${NOTES})
source_group(python FILES ${PYTHON})
source_group(views FILES ${VIEWS})

add_executable(${PROJECT_NAME}
	supersonicai/main.cpp
	.gitignore
	${AGENTS}
	${ML}
	${NETWORKS}
	${NOTES}
	${PYTHON}
	${VIEWS}
)

include_directories(..)

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