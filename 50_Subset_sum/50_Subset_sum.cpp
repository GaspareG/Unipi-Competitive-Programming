/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/subset-sum-problem/0>

  Solution description:

    let S = V[0]+V[1]+...+V[N-1]
    the problem can be reduce to check if S/2 can be obtained
    as sum of elements in V.

    if S is odd then is sure impossibile
    otherwise is a dynamic programming problem

    dp matrix: M[N][sum/2]
    where M[i][j] = true if j can be obtained as sum of elements in
                          V[0...i]
                    false otherwise

    base cases:
    - M[i][0] = true (0 is always obtainaible)
    - M[0][j] = false (i don't have numbers to use)
    - M[i][j] = M[i-1][j] if V[i] > j (number too big)
    - M[i][j] = M[i-1][j] || M[i-1][j-V[i]] otherwise

  Time  complexity: O(T*N*S)
  Space complexity: O(N*S)

  Where:
  - T is the number of test cases
  - N is the size of the vector
  - S is the sum of the elements in the vector

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

  for(int i=0; i<N; i++) std::cin >> V[i];
  int sum = 0;
  for(int i : V) sum += i;

  bool can = true;

  if(sum % 2 == 1)
  {
    can = false;
  }
  else
  {
    sum /= 2;
    std::vector<std::vector<bool>> M(N+1, std::vector<bool>(sum+1, false));

    for(int i=0; i<=N; i++)
    {
      for(int j=0; j<=sum; j++)
      {
        if(j == 0)
          M[i][j] = true;
        else if(i == 0)
          M[i][j] = false;
        else if(j - V[i-1] >= 0)
          M[i][j] = M[i-1][j] || M[i-1][j-V[i-1]];
        else
          M[i][j] = M[i-1][j];
      }
    }
    can = M[N][sum];
  }

  std::cout << (can ? "YES" : "NO") << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
