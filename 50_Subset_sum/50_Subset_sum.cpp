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
  int N, sum=0;

  std::cin >> N;
  std::vector<int> V(N+1, 0);

  for(int i=1; i<=N; i++) std::cin >> V[i];
  for(int i : V) sum += i;

  bool can = (sum%2) != 1;

  if(can)
  {
    sum /= 2;
    std::vector<std::vector<bool>> M(N+1, std::vector<bool>(sum+1, false));

    for(int i=0; i<=N;   i++) M[i][0] = true;
    for(int i=0; i<=sum; i++) M[0][i] = false;

    for(int i=1; i<=N; i++)
    {
      for(int j=1; j<=sum; j++)
      {
        if(j >= V[i]) M[i][j] = M[i-1][j] || M[i-1][j-V[i]];
        else          M[i][j] = M[i-1][j];
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
