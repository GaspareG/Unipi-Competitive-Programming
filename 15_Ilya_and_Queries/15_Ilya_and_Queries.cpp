/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/313/B?locale=en>

  Solution description:

    Compute the solution for each points, then compute the prefix sum of the vector.
    The solution for each query [r, l] is sol[r]-sol[l] (as r is not inclusive).

  Time  complexity: O(|S|+N)
  Space complexity: O(|S|)

  Where:
  - N is the number of queries
  - S is the input string
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
  std::string S;
  std::cin >> S;
  std::cin >> N;
  std::vector<int> sol(S.size()+1, 0);

  for(size_t i=1; i<=S.size(); i++) sol[i] = (S[i-1]==S[i-2]) ? 1 : 0;
  for(size_t i=2; i<=S.size(); i++) sol[i] += sol[i-1];
  for(int i=0; i<N; i++)
  {
    int l, r;
    std::cin >> l >> r;
    std::cout << (sol[r]-sol[l]) << std::endl;
  }

  return 0;
}
