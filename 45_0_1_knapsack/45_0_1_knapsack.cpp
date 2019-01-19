/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0>

  Solution description:

  Dynamic programming,

  matrix DP[N+1][W+1] where:

  - DP[0][i] = 0 (no objects left)
  - DP[i][0] = 0 (full bag)

  DP[i][j] = DP[i-1][j] if weight(object[i]) > j
  DP[i][j] = max(DP[i-1][j], value(object[i]) + DP[i-1][j-weight(object[i])) otherwhise

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

  std::vector<std::tuple<int,int>> O(N); // <value, weight>

  // Read values
  for(int i=0; i<N; i++) std::cin >> std::get<0>(O[i]);

  // Read weights
  for(int i=0; i<N; i++) std::cin >> std::get<1>(O[i]);

  // DP table
  std::vector<std::vector<int>> DP(N+1, std::vector<int>(W+1, 0));

  // Build table
  for(int i=0; i<=N; i++)
  {
    for(int j=0; j<=W; j++)
    {
      // No space or no object
      if(i == 0 || j == 0)
        continue;
      // Can take the object
      else if(std::get<1>(O[i-1]) <= j)
        // I can decide to take or don't
        DP[i][j] = std::max(DP[i-1][j],DP[i-1][j-std::get<1>(O[i-1])]+std::get<0>(O[i-1]));
      // Can't take the object
      else
        DP[i][j] = DP[i-1][j];
    }
  }

  // Print the result
  std::cout << DP[N][W] << std::endl;

}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
