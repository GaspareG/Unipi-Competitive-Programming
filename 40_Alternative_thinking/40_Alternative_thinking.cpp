/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/603/A?locale=en>

  Solution description:

    The solution is simply the length of the longest alternating sequence + 2,
    or N if greater

  Time  complexity: O(N)
  Space complexity: O(N)

  Where:
  - N is the size of the input string
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

  int N, sol=1;
  std::string S;
  std::cin >> N;
  std::cin >> S;
  for(int i=0; i<N-1; i++) sol += (S[i] != S[i+1]);
  std::cout << std::min(N, sol+2);

  return 0;
}
