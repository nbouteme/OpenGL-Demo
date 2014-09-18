############################################################

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

if (COMMAND cmake_policy)
	cmake_policy (SET CMP0003 NEW)
endif (COMMAND cmake_policy)

PROJECT (opengl-demo)


############################################################

# Options

# Set compiler flags
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

# Fuck libboost for not providing boost.pc or fucking something
# Find libraries the proper way
INCLUDE (FindPkgConfig)

# Compiler options
LINK_DIRECTORIES (
#	${_LIBRARY_DIRS}
	${CMAKE_SOURCE_DIRECTORY}
	)

#ADD_DEFINITIONS (
#	${CFLAGS}
#	)

#INCLUDE_DIRECTORIES (
#	${_INCLUDE_DIRS}
#	${LIBTORRENT_INCLUDE_DIRS}
#	)

ADD_SUBDIRECTORY (src)
