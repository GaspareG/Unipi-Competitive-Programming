/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <url>

  Solution description:

    Count how many times each position is counted in all the queries,
    to do this is enough to use a fenwick tree with range update.

    After found the count vector, sort it with the original array.
    The solution is the sum of freq[idx]*V[idx]

  Time  complexity: O((Q+N)*log(N))
  Space complexity: O(N)

  Where:
  - N is the size of input vector
  - Q is the number of queries

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

template <typename T>
class fenwick
{
  int N;
  std::vector<T> ft;

  public:

    fenwick(int size) : N(size){ ft = std::vector<T>(N+1, 0); }

    T query(int b)
    {
      T sum = 0;
      for (; b; b -= (b&(-b))) sum += ft[b];
      return sum;
    }

    void update(int k, T v){ for (; k <= N; k += (k&(-k))) ft[k] += v; }

    void update(int i, int j, T v)
    {
      update(i, v);
      update(j + 1, -v);
    }
};

int main()
{
  std::ios_base::sync_with_stdio(false);

  long long int N, Q, l, r, sol = 0;

  std::cin >> N >> Q;
  std::vector<long long int> V(N+1, 0);
  std::vector<long long int> f(N+1, 0);
  fenwick<long long int> ft(N+1);

  for(int i=1; i<=N; i++) std::cin >> V[i];

  for(int i=0; i<Q; i++)
  {
    std::cin >> l >> r;
    ft.update(l, r, 1);
  }

  for(int i=1; i<=N; i++) f[i] = ft.query(i);

  std::sort(V.begin()+1, V.end());
  std::sort(f.begin()+1, f.end());

  for(int i=1; i<=N; i++) sol += V[i]*f[i];

  std::cout << sol << std::endl;

  return 0;
}
