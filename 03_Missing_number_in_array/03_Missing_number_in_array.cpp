/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/missing-number-in-array/0>

  Solution description:

  Just the property of the xor:

  sol = (1^2^3^...^N^V[0]^V[1]^...^V[N-2])

  As V contains all the number from 1 to N except one,
  every number in [1, N] is cancelled by exact one V[i],
  except one: the missing number.

  Time  complexity: O(T*N)
  Space complexity: O(1)

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
  int N, tmp;
  std::cin >> N;
  int sol=N;

  for(int i=1; i <= N-1; i++)
  {
    std::cin >> tmp;
    sol = sol ^ i ^ tmp;
  }

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
