/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/37/A?locale=en>

  Solution description:

    Keep max frequency and number of distinct elements

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

  int N, m=0, c=0, x=0;
  std::cin >> N;
  std::vector<int> V(1001, 0);

  for(int i=0; i<N; i++)
  {
    std::cin >> x;
    V[x]++;
    if(V[x] == 1) c++;
    m = std::max(m, V[x]);
  }

  std::cout << m << " " << c << std::endl;
  return 0;
}
