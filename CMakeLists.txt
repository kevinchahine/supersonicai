cmake_minimum_required(VERSION 3.22)

SET(PROJECT_NAME supersonicai)
project(${PROJECT_NAME})

set(AGENTS 
)

set(ML
)

set(PYTHON 
	# "supersonicai/python/"
)

source_group(agents FILES ${AGENTS})
source_group(ml FILES ${ML})
source_group(python FILES ${PYTHON})

add_executable(${PROJECT_NAME}
	supersonicai/main.cpp
	${AGENTS}
	${ML}
	${PYTHON}
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