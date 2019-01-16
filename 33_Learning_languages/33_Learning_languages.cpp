/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/277/A?locale=en>

  Solution description:


  Time  complexity: O()
  Space complexity: O()

  Where:

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

  bool SameSet(int x, int y){ return Find(x) == Find(y); }

  int Find(int x) { return uf[x] == x ? x : uf[x] = Find(uf[x]); }

  void Union(int x, int y)
  {
    x = Find(x);
    y = Find(y);
    if(x == y) return;

    if(rank[x] < rank[y]) uf[x] = y;
    else if(rank[x] > rank[y]) uf[y] = x;
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

  int N, M;

  std::cin >> N >> M;
  std::vector<std::vector<int>> V(M+1);

  int sets = N;
  int zero = 0;

  for(int i=1; i<=N; i++)
  {
    int x;
    std::cin >> x;
    if(x == 0) zero++;
    for(int j=0; j<x; j++)
    {
      int y;
      std::cin >> y;
      V[y].push_back(i);
    }
  }

  struct unionFind uf(N+1);
  for(int i=1; i<=M; i++)
    for(int j=1; j<V[i].size(); j++)
    {
        if(uf.SameSet(V[i][0], V[i][j])) continue;
        sets--;
        uf.Union(V[i][0], V[i][j]);
    }

  int sol = 0;

  if(zero == N)
    sol = N;
  else
    sol = sets-1+zero;

  for(int i=1; i<=N; i++)
    std::cout << "UF " << i << " " << uf.Find(i) << std::endl;

  std::cout << "SETS " << sets << std::endl;
  std::cout << "ZERO " << zero << std::endl;

  std::cout << sol << std::endl;

  return 0;
}
