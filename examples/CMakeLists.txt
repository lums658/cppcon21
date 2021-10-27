# This source code is licensed under the license found in the
# LICENSE file in the root directory of this source tree.

add_executable(graphs.exe graphs.cpp)
set_target_properties(graphs.exe PROPERTIES
            CXX_STANDARD 20)

add_executable(bacon.exe bacon.cpp)
set_target_properties(bacon.exe PROPERTIES
            CXX_STANDARD 20)

add_executable(imdb.exe imdb.cpp)
set_target_properties(imdb.exe PROPERTIES
            CXX_STANDARD 20)

add_executable(ospf.exe ospf.cpp)
set_target_properties(ospf.exe PROPERTIES
            CXX_STANDARD 20)
