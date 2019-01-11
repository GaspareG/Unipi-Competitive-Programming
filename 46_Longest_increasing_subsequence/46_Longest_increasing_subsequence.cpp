/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0>

  Solution description:

    Dynamic programming problem

    DP vector: LIS[i] = longest increasing sub of V[0..i]

    LIS[i] = 1 + max(LIS[j] | 1 <= j < i && S[j] < S[i])
           = 1  if j not exist

    A naive implementation of this algorithm is O(N²),
    we can speedup the solution to O(N*log(N)) by a binary search
    over a set

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

void solve()
{
  int N;

  std::cin >> N;
  std::vector<int> V(N);
  std::set<int> S;

  for(int i=0; i<N; i++) std::cin >> V[i];

  for(int i=0; i<N; i++)
  {
    auto it = S.lower_bound(V[i]);
    if(it != S.end()) S.erase(it);
    S.insert(V[i]);
  }

  std::cout << S.size() << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
