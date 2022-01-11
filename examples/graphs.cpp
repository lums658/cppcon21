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
// Simple program to make sure graphs comprised of various combinations of 
// containers can compile and will work with adaptors and algorithms
// 

#include <list>
#include <vector>

#include "bfs_edge_range.hpp"
#include "imdb-graph.hpp"
#include "karate-graph.hpp"
#include "ospf-graph.hpp"
#include "spice-graph.hpp"
#include "utilities.hpp"

#include <vector>

int main() {

  /**
   * Karate is only represented as index edge list and index adjacency list
   */
  std::vector<std::vector<size_t>> G(34);
  static_assert(adjacency_list<decltype(G)>);
  push_back_fill(karate_index_edge_list, G, false, 0);

  std::vector<std::list<std::tuple<size_t>>> H(34);
  static_assert(adjacency_list<decltype(H)>);
  push_back_fill(karate_index_edge_list, H, false, 0);
  push_back_fill(karate_index_edge_list, H, false, 0);

  std::vector<std::list<std::tuple<size_t, double>>> I(34);
  static_assert(adjacency_list<decltype(I)>);

  /**
   * Other graphs have vertices and edges tables
   */
  auto a = make_plain_graph(ospf_vertices, ospf_edges);
  auto b = make_property_graph(ospf_vertices, ospf_edges);
  auto c = make_index_graph(ospf_vertices, ospf_edges);

  auto d = make_plain_graph<decltype(ospf_vertices), decltype(ospf_edges), std::vector<std::list<size_t>>>(ospf_vertices, ospf_edges, true);

  auto e = make_index_graph<decltype(ospf_vertices), decltype(ospf_edges), std::vector<std::vector<std::tuple<size_t, size_t>>>>(
      ospf_vertices, ospf_edges, true);

  auto [f, g] = make_plain_bipartite_graphs<>(movies, actors, movies_actors);
  auto h      = make_plain_bipartite_graph(movies, actors, movies_actors, 0);
  auto i      = make_plain_bipartite_graph(movies, actors, movies_actors, 1);

  auto [j, k] = make_plain_bipartite_graphs<decltype(movies), decltype(actors), decltype(movies_actors), std::vector<std::list<size_t>>>(
      movies, actors, movies_actors);
  auto l = make_plain_bipartite_graph<decltype(movies), decltype(actors), decltype(movies_actors), std::vector<std::list<size_t>>>(
      movies, actors, movies_actors, 0);
  auto m = make_plain_bipartite_graph<decltype(movies), decltype(actors), decltype(movies_actors), std::vector<std::list<size_t>>>(
      movies, actors, movies_actors, 1);

  auto n = make_plain_graph<decltype(spice_vertices), decltype(spice_edges), std::vector<std::list<int>>>(spice_vertices, spice_edges);
  auto o =
      make_plain_graph<decltype(spice_vertices), decltype(spice_edges_values), std::vector<std::list<int>>>(spice_vertices, spice_edges_values);
  auto p = make_index_graph(spice_vertices, spice_edges);
  auto q = make_index_graph(spice_vertices, spice_edges_values);
  auto r = make_property_graph(spice_vertices, spice_edges);
  auto s = make_property_graph(spice_vertices, spice_edges_values);

  bfs_edge_range(n, 1);
  bfs_edge_range(o, 1);
  bfs_edge_range(p, 1);
  bfs_edge_range(q, 0);

  return 0;
}
