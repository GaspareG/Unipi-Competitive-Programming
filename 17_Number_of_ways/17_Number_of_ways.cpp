/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/466/C?locale=en>

  Solution description:

    If the sum is not == 0 modulo 3 then impossibile
    Else

    Find prefixs that sums up to sum/3 and put an 1 to their position in an array
    Compute the prefix sum of this array.

    Find the suffix at pos i that sums up to sum/3 and sum ways[i-2]

  Time  complexity: O(N)
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
#include <numeric>
#include <cmath>

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<long long int> V(N), ways(N, 0);
  for(int i=0; i<N; i++) std::cin >> V[i];

  long long int sum = std::accumulate(V.begin(), V.end(), 0ll);
  long long int sol = 0ll, tmp = 0ll;

  if(sum % 3ll == 0ll)
  {
    sum /= 3ll;

    for(int i=0; i<N; i++)
    {
      tmp += V[i];
      if(tmp == sum) ways[i] = 1ll;
    }

    std::partial_sum(ways.begin(), ways.end(), ways.begin());
    tmp = 0ll;

    for(int i=N-1; i>1; i--)
    {
      tmp += V[i];
      if(tmp == sum) sol += ways[i-2];
    }
  }

  std::cout << sol << std::endl;

  return 0;
}
