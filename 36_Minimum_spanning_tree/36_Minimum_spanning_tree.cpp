/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://www.spoj.com/problems/MST/>

  Solution description:

	Implementation of Kruskal algorithm with the Disjoint set data struct
	
	Create a DJS of size V
	Process edge(u,v,w) in increasing order of w
	Take (u,v) if u and v are not in the same set and add w to the solution

  Time  complexity: O(E*log(V))
  Space complexity: O(V+E)

  Where:
  - V is the number of vertices
  - E is the number of edges

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
#include <numeric>
#include <cmath>

struct unionFind
{
  std::vector<int> uf, rank;

  unionFind(int n)
  {
    uf = std::vector<int>(n);
    rank = std::vector<int>(n, 0);
    std::iota(uf.begin(), uf.end(), 0);
  }

  bool SameSet(int x, int y)
  {
    return Find(x) == Find(y);
  }

  // find with path compression
  int Find(int x)
  {
    return uf[x] == x ? x : uf[x] = Find(uf[x]);
  }

  // union with union by rank
  void Union(int x, int y)
  {
    x = Find(x);
    y = Find(y);

    if(rank[x] < rank[y])
    {
      uf[x] = y;
    }
    else if(rank[x] > rank[y])
    {
      uf[y] = x;
    }
    else
    {
        uf[y] = x;
        rank[x]++;
    }
  }

};

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N, M, u, v, w;
  long long int sol = 0ll;

  std::cin >> N >> M;

  struct unionFind uf(N);
  std::vector<std::tuple<int,int,int>> E;

  for(int i=0; i<M; i++)
  {
    std::cin >> u >> v >> w;
    E.emplace_back(w, --u, --v);
  }

  std::sort(E.begin(), E.end());

  for(int i=0; i<M; i++)
  {
    int w = std::get<0>(E[i]);
    int u = std::get<1>(E[i]);
    int v = std::get<2>(E[i]);
    if(!uf.SameSet(u, v))
    {
      uf.Union(u, v);
      sol += w;
    }
  }

  std::cout << sol << std::endl;

  return 0;
}
