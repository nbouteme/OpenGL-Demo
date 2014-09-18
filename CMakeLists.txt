############################################################

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

if (COMMAND cmake_policy)
	cmake_policy (SET CMP0003 NEW)
endif (COMMAND cmake_policy)

PROJECT (opengl-demo)


############################################################

# Set compiler flags
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wextra -pedantic -fno-exceptions")

INCLUDE (FindPkgConfig)

PKG_SEARCH_MODULE(GLFW REQUIRED glfw3)
PKG_SEARCH_MODULE(GL REQUIRED gl)


# Compiler options
LINK_DIRECTORIES (
	${CMAKE_SOURCE_DIRECTORY}
	)


INCLUDE_DIRECTORIES (
	${GLFW_INCLUDE_DIRS}
	${GL_INCLUDE_DIRS}
	)


ADD_SUBDIRECTORY (src)
