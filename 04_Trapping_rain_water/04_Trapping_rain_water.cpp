/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/trapping-rain-water/0>

  Solution description:

    Two-pointer algorithm

    I keep two index left and right, starting from 0 and N-1 and a water height variable.

    At each step I move the index with the lowest water height,
    the height is the maximum of all the water height seen before
    and we add height - V[idx] at each step, which is the water trapped by x=idx

  Time  complexity: O(T*N)
  Space complexity: O(N)

  Where:
  - T is the number of test cases
  - N is the size of the input vector
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

  long long sol = 0ll;
  int left = 0;
  int right = N-1;
  int height = 0;

  while(left < right)
  {
    if(V[left] <= V[right])
    {
      height = std::max(height, V[left]);
      sol += height - V[left++];
    }
    else
    {
      height = std::max(height, V[right]);
      sol += height - V[right--];
    }
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
