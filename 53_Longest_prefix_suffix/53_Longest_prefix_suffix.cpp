/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0>

  Solution description:

    The solution is simply the last element in the KMP
    preprocessing table (the border array)

  Time  complexity: O(T*|S|)
  Space complexity: O(|S|)

  Where:
  - T is the number of test cases
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

void solve()
{
  std::string S;
  std::cin >> S;

  size_t N = S.size();
  std::vector<int> pref(N);

  for (int i=1; i<N; i++)
  {
    int j = pref[i-1];
    while (j > 0 && S[i] != S[j]) j = pref[j-1];
    if (S[i] == S[j]) j++;
    pref[i] = j;
  }

  std::cout << pref[N-1] << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
