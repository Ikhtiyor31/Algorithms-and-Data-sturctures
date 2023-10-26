#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;
int findShortestPath(unordered_map<string, vector<string>> graph, unordered_set<string> & visited, string src, string dst) {
  
  if (src == dst)
    return 0;
  
  if (visited.count(src))
    return -1;
  
  visited.insert(src);
  int shortest = -1;
  for(string children: graph[src]) {
    int count = findShortestPath(graph, visited, children, dst);
    if (count != -1 && (shortest == -1 || shortest > count + 1)) {
        shortest = count + 1; 
    }
  }
  visited.erase(src);
  return shortest;
}
int shortestPath(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB) {
  unordered_map<string, vector<string>> graph;
  unordered_set<string> visited;
  for(tuple<string, string> pair: edges) {
    auto [a, b] = pair;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return findShortestPath(graph, visited, nodeA, nodeB);
}

