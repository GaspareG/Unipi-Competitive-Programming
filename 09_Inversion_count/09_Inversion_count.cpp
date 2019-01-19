/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://www.spoj.com/problems/INVCNT/>

  Solution description:

  We iterate the vector for i from N-1 to 0
  at each step the inversion for V[i] is equal to the number of elements
  in V[i+1..N-1] less than V[i].

  A naive solution is to check all the right part of the vector with a
  complexity of O(N²), we can speed up the solution by using a fenwick tree
  to query the right part of the vector

  Time  complexity: O(T*N*log(N))
  Space complexity: O(N)

  Where:
  - T is the number of test cases
  - N is the size of the input vector
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


template <class T>
struct fenwick_tree {
  std::vector<T> x;
  fenwick_tree(size_t n) : x(n+1) { }

  // initialize by a constant
  fenwick_tree(size_t n, T a) : x(n+1, a)
  {
    x[0] = 0;
    for (int k = 1; k+(k&-k) <= n; ++k) x[k+(k&-k)] += x[k];
  }

  // initialize by a std::vector
  fenwick_tree(std::vector<T> y) : x(y.size()+1)
  {
    for (int k = 0; k < y.size(); ++k) x[k+1] = y[k];
    for (int k = 1; k+(k&-k) < x.size(); ++k) x[k+(k&-k)] += x[k];
  }

  // b[k] += a
  void add(int k, T a)
  {
    for (++k; k < x.size(); k += k&-k) x[k] += a;
  }

  // sum b[0,k)
  T sum(int k)
  {
    T s = 0;
    for (++k; k > 0; k &= k-1) s += x[k];
    return s;
  }

};

void solve()
{
  int N;
  long long sol = 0ll;
  std::cin >> N;
  std::vector<int> V(N);
  struct fenwick_tree<int> ft(10000001);

  for(int i=0; i<N; i++) std::cin >> V[i];
  for(int i=N-1; i>=0; i--)
  {
    sol += ft.sum(V[i]);
    ft.add(V[i]+1, 1);
  }

  std::cout << sol << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
