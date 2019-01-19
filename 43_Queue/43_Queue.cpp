/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/141/C?locale=en>

  Solution description:

    Sort by number of persons,
    If any person had more person than index then is impossibile.
    Else put every person in idx-height[idx]

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
  std::vector<std::pair<int, std::string>> C(N);
  std::vector<int> H(N, 0);
  for(int i=0; i<N; i++) std::cin >> C[i].second >> C[i].first;

  std::sort(C.begin(), C.end());

  bool check = true;
  for(int i=0; i<N; i++) if(C[i].first > i) check = false;

  if(check)
  {
    for(int i=0; i<N; i++) H.insert(H.begin()+i-C[i].first, i);
    for(int i=0; i<N; i++) C[H[i]].first = i+1;
    for(int i=0; i<N; i++) std::cout << C[i].second << " " << C[i].first << std::endl;
  }
  else
  {
    std::cout << -1 << std::endl;
  }

  return 0;
}

