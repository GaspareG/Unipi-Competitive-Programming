/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/424/B?locale=en>

  Solution description:

    Sort the cities by distance from (0,0)
    Find the first index i such that S+population(city[0..i]) >= 1.000.000

    Then return the squared distance from i-th city, -1 if not exists

  Time  complexity: O(N*log(N))
  Space complexity: O(N)

  Where:
  - N is the size of input vector
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

  long long int N, S;
  std::cin >> N >> S;
  std::vector<std::array<int, 3>> C(N);
  for(int i=0; i<N; i++) std::cin >> C[i][0] >> C[i][1] >> C[i][2];

  if(N >= 1000000)
  {
    std::cout << 0. << std::endl;
    return 0;
  }

  std::sort(C.begin(), C.end(), [](const std::array<int, 3> &X, const std::array<int, 3> &Y)
  {
    return (X[0]*X[0]+X[1]*X[1]) < (Y[0]*Y[0]+Y[1]*Y[1]);
  });

  long long sum = 1000000-S;
  int idx = 0;
  while(idx < N)
  {
    sum -= C[idx][2];
    if(sum <= 0) break;
    idx++;
  }

  if(idx == N)
  {
    std::cout << -1 << std::endl;
  }
  else
  {
    double dist = static_cast<double>(C[idx][0]*C[idx][0]+C[idx][1]*C[idx][1]);
    std::cout.precision(8);
    std::cout << sqrt(dist) << std::endl;
  }
  return 0;
}
