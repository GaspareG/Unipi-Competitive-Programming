/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0>

  Solution description:

    Dinamic programming problem

    DP Matrix M[0..|A|][0..|B|] where

      M[i][j] = longest common subseq of A[0..i] and B[0..j]

    Base cases:

      - M[0][i] = M[i][0] = 0

    DP case:

      - M[i][j] = 1 + M[i-1][j-1]   if A[i-1] == B[i-1]
      - M[i][j] = max(M[i-1][j], M[i][j-1]) otherwise

  Time  complexity: O(T*|A|*|B|)
  Space complexity: O(|A|*|B|)

  Where:
  - T is the number of test cases
  - A is the first string
  - B is the second string

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
  int l1, l2;
  std::string s1, s2;

  std::cin >> l1 >> l2;
  std::cin >> s1 >> s2;

  std::vector<std::vector<int>> M(l1+1, std::vector<int>(l2+1, 0));

  for(int i=0; i<=l1; i++)
  {
    for(int j=0; j<=l2; j++)
    {
      if(i == 0 || j == 0)
      {
        continue;
      }
      else if(s1[i-1] == s2[j-1])
      {
        M[i][j] = M[i-1][j-1]+1;
      }
      else
      {
        M[i][j] = std::max(M[i-1][j], M[i][j-1]);
      }
    }
  }

  std::cout << M[l1][l2] << std::endl;

}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
