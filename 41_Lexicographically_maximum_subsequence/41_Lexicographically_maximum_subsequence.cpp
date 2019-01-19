/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/196/A?locale=en>

  Solution description:

    Save for each char a vector with sorted position of char in string
    Start from z to a, print all the char with index > right and set right=index
    The algorithm is linear as the inside for loop is executed |S| times.

  Time  complexity: O(|S|)
  Space complexity: O(|S|)

  Where:
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
  std::string S;
  std::cin >> S;

  std::vector<int> occ[26];
  for(size_t i=0; i<S.size(); i++) occ[S[i]-'a'].push_back(i);

  int right = 0;
  for(int i = 25; i>= 0; i--)
    for(int j : occ[i])
      if(j >= right)
      {
        std::cout << static_cast<char>('a'+i);
        right = j;
      }

  std::cout << std::endl;

  return 0;
}
