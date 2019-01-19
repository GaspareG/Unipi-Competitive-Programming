/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0>

  Solution description:

    Standard dynamic programming,

  Time  complexity: O(T*N*W)
  Space complexity: O(N*W)

  Where:
  - T is the number of test cases
  - N is the number of objects
  - W is the maximum capacity

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
  // Read input
  int N, W;
  std::cin >> N >> W;

  std::vector<std::array<int, 2>> O(N); // <value, weight>

  // Read values and weights
  for(int i=0; i<N; i++) std::cin >> O[i][0];
  for(int i=0; i<N; i++) std::cin >> O[i][1];

  // DP table
  std::vector<int> DP(W+1, 0);

  // Build table
  for(int i=0; i<N; i++)
    for(int j=W-O[i][1]; j>=0; j--)
        DP[j+O[i][1]] = std::max(DP[j+O[i][1]], DP[j]+O[i][0]);

  // Print the result
  std::cout << *std::max_element(DP.begin(), DP.end()) << std::endl;

}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}

