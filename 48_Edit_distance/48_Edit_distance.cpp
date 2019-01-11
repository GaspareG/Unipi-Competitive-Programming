/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/edit-distance/0>

  Solution description:

    Standard dinamic programming,
    keep a DP matrix M of size (|A|+1)*(|B|+1)

    base cases:
      - M[i][0] = i
      - M[0][j] = j

    recursion function:
      - M[i][j] = M[i-1][j-1] if A[i-1] == A[j-1]
      - M[i][j] = 1 + min(M[i-1][j-1], M[i-1][j], M[i][j-1]) otherwise

    The solution is in M[|A|][|B|]

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

  for(int i=0; i<=l1; i++) M[i][0] = i;
  for(int j=0; j<=l2; j++) M[0][j] = j;

  for(int i=1; i<=l1; i++)
  {
    for(int j=1; j<=l2; j++)
    {
      if(s1[i-1] == s2[j-1])
      {
        M[i][j] = M[i-1][j-1];
      }
      else
      {
        M[i][j] = M[i-1][j-1];
        M[i][j] = std::min(M[i][j], M[i-1][j]);
        M[i][j] = std::min(M[i][j], M[i][j-1]);
        M[i][j]++;
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
