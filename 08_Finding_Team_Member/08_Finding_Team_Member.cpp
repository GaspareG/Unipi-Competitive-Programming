/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/579/B?locale=en>

  Solution description:

    Just sort, consider from biggest to smallest and assign
    team mates in this order if peoples are free

  Time  complexity: O(N)
  Space complexity: O(1)

  Where:
  - N is the number of teams
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

  int N, x;
  std::cin >> N;
  N *= 2;

  std::vector<std::array<int, 2>> person(1000001, {0,0});
  std::vector<int> mates(1001, 0);
  std::vector<bool> seen(1001, false);
  seen[0] = true;

  for(int i=1; i<=N; i++)
    for(int j=1; j<i; j++)
    {
      std::cin >> x;
      person[x][0]=i;
      person[x][1]=j;
    }

  for(int i=1000000; i>0; i--)
  {
    if(seen[person[i][0]]) continue;
    if(seen[person[i][1]]) continue;

    mates[person[i][0]] = person[i][1];
    mates[person[i][1]] = person[i][0];

    seen[person[i][0]] = true;
    seen[person[i][1]] = true;
  }

  for(int i=1; i<=N; i++) std::cout << mates[i] << " ";
  std::cout << std::endl;

  return 0;
}

