/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/596/B?locale=en>

  Solution description:

    The solution is simply the some of adjacent absolute differents (with 0 as initial)

  Time  complexity: O(N)
  Space complexity: O(1)

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

  long long int N, sol=0, last=0, x=0;
  std::cin >> N;

  for(int i=0; i<N; i++)
  {
    std::cin >> x;
    sol += std::abs(x-last);
    last = x;
  }

  std::cout << sol << std::endl;
  return 0;
}
