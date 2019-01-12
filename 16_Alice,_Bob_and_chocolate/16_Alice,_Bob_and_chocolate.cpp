/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/6/C?locale=en>

  Solution description:

    Just simulate by keeping two pointers for Alice on the left
    and Bob on the right

  Time  complexity: O(N)
  Space complexity: O(N)

  Where:
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

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<int> V(N);
  for(int i=0; i<N; i++) std::cin >> V[i];

  int lIdx = 0;
  int rIdx = N-1;

  int lTime = 0;
  int rTime = 0;

  while(lIdx <= rIdx)
  {
    if(lTime <= rTime)
    {
      lTime += V[lIdx];
      lIdx++;
    }
    else
    {
      rTime += V[rIdx];
      rIdx--;
    }
  }

  std::cout << lIdx << " " << (N-lIdx) << std::endl;

  return 0;
}
