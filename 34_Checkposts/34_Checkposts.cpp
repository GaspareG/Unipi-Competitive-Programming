/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <url>

  Solution description:

    Find the scc.
    The cost is the sum of the minimum cost of each cc.
    The number of ways is the product of the number of node with the minimum cost in each cc.

  Time  complexity: O(N+M)
  Space complexity: O(N+M)

  Where:
  - N is the number of vertices
  - M is the number of edges
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

void dfs(const std::vector<std::vector<int>> &G, std::vector<bool> &seen, std::stack<int> &S, int u)
{
  seen[u] = true;
  for(auto v : G[u])
    if(!seen[v])
      dfs(G, seen, S, v);
  S.push(u);
}

void dfs(const std::vector<std::vector<int>> &G, std::vector<bool> &seen, int u, std::vector<int> &cc)
{
  seen[u] = true;
  cc.push_back(u);
  for(auto v : G[u])
    if(!seen[v])
      dfs(G, seen, v, cc);
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N;
  std::vector<int> V(N);
  std::vector<bool> seen(N, false);
  std::vector<std::vector<int>> G(N);
  std::vector<std::vector<int>> Gt(N);
  std::vector<std::vector<int>> scc;

  // Read cost
  for(int i=0; i<N; i++) std::cin >> V[i];

  // Read edges
  std::cin >> M;
  for(int i=0; i<M; i++)
  {
    int x, y;
    std::cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    Gt[y].push_back(x);
  }

  // Find SCC
  std::stack<int> S;
  for(int i=0; i<N; i++)
    if(!seen[i])
      dfs(G, seen, S, i); // first dfs

  std::fill(seen.begin(), seen.end(), false);

  while(!S.empty())
  {
    int top = S.top();
    S.pop();

    if(seen[top]) continue;

    std::vector<int> cc;
    cc.reserve(1<<14);
    dfs(Gt, seen, top, cc);
    scc.push_back(cc);
  }

  // For each cc count cost and ways
  long long int sol = 0ll, way = 1ll;

  for(size_t i=0; i<scc.size(); i++)
  {
    long long me = V[scc[i][0]];
    long long co = 0;
    for(auto v : scc[i])
      if(V[v] == me) co++;
      else if(V[v] < me) me = V[v], co=1;

    sol += me;
    way = (way*co) % 1000000007;
  }

  std::cout << sol << " " << way << std::endl;

  return 0;
}
