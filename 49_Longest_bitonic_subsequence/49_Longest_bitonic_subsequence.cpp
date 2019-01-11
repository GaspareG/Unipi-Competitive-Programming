/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0>

  Solution description:

    Dynamic programming problem,
    the LDS can be reduced to find the LIS of the vector
    and the LIS of the reversed vector,
    the solution is the maximum sum between the two lis at the same position
    (minus one as we have considered two times the element in the position)

  Time  complexity: O(T*N*log(N))
  Space complexity: O(N)

  Where:
  - S is the number of test cases
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
  std::vector<int> LIS(N), LDS(N);

  for(int i=0; i<N; i++) std::cin >> V[i];

  // LIS
  std::set<int> S;
  for(int i=0; i<N; i++)
  {
    auto it = S.lower_bound(V[i]);
    if(it != S.end()) S.erase(it);
    S.insert(V[i]);
    LIS[i] = S.size();
  }

  // LDS
  S.clear();
  for(int i=N-1; i>=0; i--)
  {
    auto it = S.lower_bound(V[i]);
    if(it != S.end()) S.erase(it);
    S.insert(V[i]);
    LDS[i] = S.size();
  }

  // Find Max LBS
  int sol = 0;
  for(int i=0; i<N; i++)
    sol = std::max(sol, LIS[i]+LDS[i]-1);

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
