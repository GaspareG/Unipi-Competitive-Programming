/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/652/D?locale=en>

  Solution description:

    Use a fenwick tree to count how many segments are in range,
    to do this compress all the coordinates, sort by end positions and
    query the ft.

  Time  complexity: O(N*log(N))
  Space complexity: O(N)

  Where:
  - N is the number of segments
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

template <typename T>
class fenwick
{
  int N;
  std::vector<T> ft;

  public:

    fenwick(int size) : N(size){ ft = std::vector<T>(N+1, 0); }

    void update(int k, T v){ for (; k <= N; k += (k&(-k))) ft[k] += v; }

    T query(int b, T sum = 0)
    {
      for (; b; b -= (b&(-b))) sum += ft[b];
      return sum;
    }

};

int main()
{
  std::ios_base::sync_with_stdio(false);

  // Read input
  int N, count = 0;
  std::cin >> N;
  std::vector<int> S(N), E(N);
  std::vector<int> idx(N), sol(N);
  std::map<int, int> X;

  for(int i=0; i<N; i++) std::cin >> S[i] >> E[i];

  // Compress coordinates
  for(int i=0; i<N; i++) X[S[i]] = X[E[i]] = 0;
  for(auto [k, v] : X) X[k] = ++count;
  for(int i=0; i<N; i++) S[i] = X[S[i]], E[i] = X[E[i]];

  // Sort segments by end position
  std::iota(idx.begin(), idx.end(), 0);
  std::sort(idx.begin(), idx.end(), [&](int a, int b){ return E[a] < E[b]; });

  // Compute solution for each segment
  fenwick<int> ft(2*N);
  for(int i=0; i<N; i++)
  {
    int id = idx[i];
    // Number of segments in [L, R]
    sol[id] = ft.query(E[id]) - ft.query(S[id]-1);
    ft.update(S[id], 1); // Add segment to ft
  }

  // Print solutions
  for(int i=0; i<N; i++) std::cout << sol[i] << std::endl;

  return 0;
}
