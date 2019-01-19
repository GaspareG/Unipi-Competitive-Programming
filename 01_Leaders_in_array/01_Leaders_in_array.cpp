/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0>

  Solution description:

    Iterate the array for i from N-1 to 0,
    keep a variable max_right that contains the maximum element
    in a range (i, N), if V[i] >= max_right add to the leaders.
    At the end of each step update max_right if V[i] is greater.
    Pay attention to print the leaders in the inverted order as
    we are scanning the array from right to left

  Time  complexity: O(T*N)
  Space complexity: O(N)

  Where:
  - T is the number of test cases
  - N is the size of the array
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
  std::vector<long long int> V(N);
  std::vector<long long int> sol;
  long long int max_right = -1;

  for(int i=0; i<N; i++) std::cin >> V[i];

  for(auto i=N-1; i>=0; i--)
  {
    if(V[i] >= max_right) sol.push_back(V[i]);
    max_right = std::max(max_right, V[i]);
  }

  if(sol.size() > 0)
    for(int i(sol.size()-1); i>=0; i--) std::cout << sol[i] << (i>0?" ":"");

  std::cout << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();
  return 0;
}
