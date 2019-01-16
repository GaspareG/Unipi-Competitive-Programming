/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <url>

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
#include <cmath>

template <typename T>
class fenwick
{
  int N;
  std::vector<T> ft;

  public:

    fenwick(int size) : N(size)
    {
      ft = std::vector<T>(N+1, 0);
    }

    T query(int b)
    {
      T sum = 0;
      for (; b; b -= (b&(-b))) sum += ft[b];
      return sum;
    }

    void update(int k, T v)
    {
      for (; k <= N; k += (k&(-k))) ft[k] += v;
    }
};

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N;
  std::vector<std::array<int, 2>> S;
  std::vector<int> V(N);
  std::iota(V.begin(), V.end(), 0);
  for(int i=0; i<V; i++) std::cin >> S[i][0] >> S[i][1];
  return 0;
}
