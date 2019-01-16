/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/459/D?locale=en>

  Solution description:

    We first compress the array, then we use a fenwick tree TODO

  Time  complexity: O(N*log(N))
  Space complexity: O(N)

  Where:
  - N is the size of input vector

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

  // Read input vector and compress
  int N, count = 0;
  std::cin >> N;
  std::vector<int> V(N), freq(N+1, 0), remove(N+1, 0);
  for(int i=0; i<N; i++) std::cin >> V[i];

  // Compress coordinates
  std::map<int,int> S;
  for(int i=0; i<N; i++) S[V[i]] = 0;
  for(auto [k,v] : S) S[k] = count++;
  for(int i=0; i<N; i++) V[i] = S[V[i]];

  // Suffix
  fenwick<int> ft(N+1);
  for(int i=N-1; i>=0; i--)
  {
    remove[i] = ++freq[V[i]];
    ft.update(freq[V[i]]+1, 1);
  }

  // Prefix + solution
  freq = std::vector<int>(N+1, 0);
  long long int sol = 0;

  for(int i=0; i<N; i++)
  {
    ft.update(remove[i]+1, -1);
    freq[V[i]]++;
    sol += ft.query(freq[V[i]]) - ft.query(1);
  }

  std::cout << sol << std::endl;

  return 0;
}


