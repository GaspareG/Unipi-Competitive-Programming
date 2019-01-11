/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0>

  Solution description:

  Simply use the kadane algorithm.
  Iterate over the vector for i from 0 to N-1.
  Keep a variable temp_sum, at each step add V[i] to temp_sum,
  if temp_sum < 0 then set temp_sum = 0.

  The solution is the maximum value of temp_sum at each step.

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
  // Read the input
  int N;
  std::cin >> N;
  std::vector<long long int> V(N);
  for(int i=0; i<N; i++) std::cin >> V[i];

  // Solution, max value of temp_sum o max element in V
  long long int sol = *std::max_element(V.begin(), V.end());
  // Temporary window sum
  long long int temp_sum = 0ll;

  for(int i=0; i<N; i++)
  {
    temp_sum = std::max(0ll, temp_sum);
    temp_sum += V[i];
    sol = std::max(sol, temp_sum);
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
