# This source code is licensed under the license found in the
# LICENSE file in the root directory of this source tree.

cmake_minimum_required(VERSION 3.12)

project(cppcon21_graph_demos LANGUAGES CXX VERSION 0.1)

add_library(graph INTERFACE)

include_directories(graphs)
include_directories(include)
add_subdirectory(examples)
