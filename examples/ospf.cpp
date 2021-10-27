//
// Copyright 2021 Andrew Lumsdaine
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Recapitulation of OSPF routing example from Boost Graph Library book 
// by Siek, Lumsdaine, and Lee
//

#include <iomanip>
#include <iostream>
#include <list>

#include "dijkstra.hpp"
#include "ospf-graph.hpp"
#include "utilities.hpp"

int main() {

  static_assert(adjacency_list<decltype(ospf_index_adjacency_list)>);

  auto d = dijkstra(ospf_index_adjacency_list, 5UL);

  std::cout << "----------------" << std::endl;
  std::cout << "Contents of ospf_index_adjacency_list (the correct answer)" << std::endl;

  for (size_t i = 0; i < size(ospf_vertices); ++i) {
    std::cout << std::setw(6) << ospf_vertices[i] << std::setw(6) << d[i] << std::endl;
  }

  std::cout << "----------------" << std::endl;
  std::cout << "Results from make_property_graph(osp_vertices)" << std::endl;

  auto G = make_property_graph(ospf_vertices, ospf_edges, true);

  // Alternatively
  auto H = make_property_graph<decltype(ospf_vertices), decltype(ospf_edges), 
			       std::vector<std::list<std::tuple<size_t, size_t>>>>(ospf_vertices, ospf_edges, true);
  auto I = make_property_graph<decltype(ospf_vertices), decltype(ospf_edges), 
			       std::vector<std::vector<std::tuple<size_t, size_t>>>>(ospf_vertices, ospf_edges, true);

  static_assert(adjacency_list<decltype(G)>);

  auto e = dijkstra(G, 5UL, [](auto&& e) { return std::get<1>(e); });

  for (size_t i = 0; i < size(ospf_vertices); ++i) {
    std::cout << std::setw(6) << ospf_vertices[i] << std::setw(6) << e[i] << std::endl;
  }

  std::cout << "----------------" << std::endl;
  std::cout << "Results from make_index_graph(osp_vertices)" << std::endl;

  auto J = make_index_graph(ospf_vertices, ospf_edges, true);

  auto f = dijkstra(J, 5, [](auto&& e) { return std::get<2>(ospf_edges[std::get<1>(e)]); });

  for (size_t i = 0; i < size(ospf_vertices); ++i) {
    std::cout << std::setw(6) << ospf_vertices[i] << std::setw(6) << e[i] << std::endl;
  }

  return 0;
}
