/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/320/A?locale=en>

  Solution description:

    Just check from left to right

  Time  complexity: O(1)
  Space complexity: O(1)

  Where:

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
  std::string S;
  std::cin >> S;

  bool check = true;
  size_t i = 0, N = S.size();

  for(char c : S) check &= (c == '1' || c == '4');

  while(i<N && check)
  {
    if(S[i] != '1') check = false;
    else if(i+2<N && S[i+1] == '4' && S[i+2] == '4') i += 3;
    else if(i+1<N && S[i+1] == '4') i += 2;
    else i += 1;
  }

  std::cout << (check ? "YES" : "NO") << std::endl;

  return 0;
}
