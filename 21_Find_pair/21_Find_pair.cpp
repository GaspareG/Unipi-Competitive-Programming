/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/160/C?locale=en>

  Solution description:

    Count frequency with a map, iterate over it to found the first number
    and decrease K by freq*N each time.
    Repeat the first step to find the second value.

  Time  complexity: O(N*log(N))
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

  long long int N, K, x;


  std::cin >> N >> K;
  std::map<long long int, long long int> freq;
  for(auto i=0; i<N; i++)
  {
    std::cin >> x;
    freq[x]++;
  }

  K--; // 1-based to 0-based

  // Find first number
  for (auto [k, v] : freq)
  {
    if (K < v*N)
    {
      N = v;
      std::cout << k << " ";
      break;
    }
    K -= v*N;
  }

  // Find second number
  for (auto [k, v] : freq)
  {
    if (K < v*N)
    {
      K = v;
      std::cout << k << std::endl;
      break;
    }
    K -= v*N;
  }

  return 0;
}
