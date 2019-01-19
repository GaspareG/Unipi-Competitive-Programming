/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://www.spoj.com/problems/UPDATEIT/>

  Solution description:

    Just use a datastruct which provide a range update and point query in O(log(N)).

    A fenwick tree with range update is enough.

  Time  complexity: O(T*Q*log(N))
  Space complexity: O(N)

  Where:
  - T is the number of test cases
  - N is the size of the input vector
  - Q is the sum of query/update
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
      for(; b; b -= (b&(-b))) sum += ft[b];
      return sum;
    }

    void update(int k, T v){ for (; k <= N; k += (k&(-k))) ft[k] += v; }

    void update(int i, int j, T v)
    {
      update(i, v);
      update(j + 1, -v);
    }
};

void solve()
{
  int N, U, Q;
  int l,r,v,x;
  std::cin >> N >> U;

  fenwick<long long int> ft(N+1);

  for(int i=0; i<U; i++)
  {
    std::cin >> l >> r >> v;
    ft.update(l+1, r+1, v);
  }

  std::cin >> Q;

  for(int i=0; i<Q; i++)
  {
    std::cin >> x;
    std::cout << ft.query(x+1) << std::endl;
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
