/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0>

  Solution description:

    I Keep a vector SOL[N] where SOL[i] is the
    minimum number of jump to reach V[i] and an integer right
    that keep track of the position i can reach so far.

    I iterate i from 0 to N-1, at each step i update all the SOl[k]
    for k in [right, i+V[i]] as SOL[i]+1 if possibile
    (thus if v[i] is reachable).

    The solution in linear becasure the total number of operation
    inside the second for is N.

  Time  complexity: O(T*N)
  Space complexity: O(N)

  Where:
  - T is the number of test cases
  - N is the size of the vector

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
  std::vector<int> sol(N, N);
  for(int i=0; i<N; i++) std::cin >> V[i];

  sol[0] = 0;
  int right = 1;

  for(int i=0; i<N-1; i++)
    for(right; right <= i+V[i] && right < N; right++)
      sol[right] = std::min(sol[right], sol[i]+1);

  std::cout << (sol[N-1] == N ? -1 : sol[N-1]) << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
