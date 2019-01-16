/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/277/A?locale=en>

  Solution description:

    Create an union find data struct with N sets,
    merge the employees who speak the same language.

    If no one speak no language the solution is N, otherwise
    is the number of sets - 1

  Time  complexity: O(N*log(N))
  Space complexity: O(N+M)

  Where:
  - N is the number of employees
  - M is the number of languages
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

  int N, M, x, y;
  std::cin >> N >> M;
  std::vector<std::vector<int>> V(M+1);

  int sets = N, zero = 0;

  for(int i=1; i<=N; i++)
  {
    std::cin >> x;
    if(x == 0) zero++;
    for(int j=0; j<x; j++)
    {
      std::cin >> y;
      V[y].push_back(i);
    }
  }

  struct unionFind uf(N+1);

  for(int i=1; i<=M; i++)
  {
    for(int j=1; j<V[i].size(); j++)
    {
        if(uf.SameSet(V[i][0], V[i][j])) continue;
        sets--;
        uf.Union(V[i][0], V[i][j]);
    }
  }

  std::cout << (zero == N ? N : sets-1) << std::endl;

  return 0;
}
