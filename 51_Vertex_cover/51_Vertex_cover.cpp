/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://www.spoj.com/problems/PT07X/>

  Solution description:

    Dynamic programming + DFS over a tree

    DP matrix: DP[bool taken][int node]
      - taken, if node is in the vertex cover
      - node, the root of the subtree

    Visit the tree using a DFS, on the actual node "X"
    I can decide to take it in the vertex cover or not:

      If I don't take X
        I MUST take all the children in the vertex cover
      Else
        I can decide if take or don't a child, depending of the
        size of the minimum vertex cover

  Time  complexity: O(V)
  Space complexity: O(V)

  Where:
  - V is the number of vertices in the three
*/

#include <iostream>
#include <bitset>
#include <functional>
#include <utility>
#include <tuple>
#include <limits>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>

std::vector<std::vector<int>> T;
std::vector<int> DP[2];

void vertexCover(int node, int parent)
{
  // For each adjancent node
  for(int next : T[node])
  {
    // If parent, skip to avoid loop
    if(next == parent)
      continue;

    // Recursive call on child
    vertexCover(next, node);

    // if a don't take node I must take the child
    DP[0][node] += DP[1][next];

    // if I take the node i can choose to take or don't the child
    DP[1][node] += std::min(DP[0][next], DP[1][next]);

  }

  // If a take the node increment the vertex cover
  DP[1][node]++;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N, u, v;
  std::cin >> N;

  T = std::vector<std::vector<int>>(N);
  DP[0] = std::vector<int>(N, 0);
  DP[1] = std::vector<int>(N, 0);

  // Read the tree edges
  for(int i=0; i<N-1; i++)
  {
    std::cin >> u >> v;
    u--;
    v--;
    T[u].push_back(v);
    T[v].push_back(u);
  }

  vertexCover(0, -1);

  // The solution is the minimum between
  // Take or not take the root of the tree
  std::cout << std::min(DP[0][0], DP[1][0]);

  return 0;
}
