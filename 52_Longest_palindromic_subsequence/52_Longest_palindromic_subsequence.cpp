/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0>

  Solution description:

    Dynamic programming problem,

    DP matrix: LPS[|S|][|S|] where LPS[i][j] is the solution for S[i..j]

    recurrence:
    - DP[i][j] = 0  if i > j
    - DP[i][j] = 1  if i == j
    - DP[i][j] = 2+DP[i+1][j-1]  if S[i] == S[j]
    - DP[i][j] = max(DP[i+1][j], DP[i][j-1])  if otherwise

  Time  complexity: O(T*|S|²)
  Space complexity: O(|S|²)

  Where:
  - T is the number of test cases
  - S is the input string

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

std::vector<std::vector<int>> DP;
std::string S;

int lps(int i, int j)
{
  if(DP[i][j] == -1)
  {
    if(i > j)
      DP[i][j] = 0;
    else if(i == j)
      DP[i][j] = 1;
    else if(S[i] == S[j])
      DP[i][j] = 2 + lps(i+1, j-1);
    else
      DP[i][j] = std::max(lps(i+1, j), lps(i, j-1));
  }
  return DP[i][j];
}

void solve()
{
  std::cin >> S;

  size_t len = S.size();
  DP = std::vector<std::vector<int>>(len, std::vector<int>(len, -1));

  std::cout << lps(0, len-1) << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
