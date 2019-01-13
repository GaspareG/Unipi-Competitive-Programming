/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/contest/545/problem/C?locale=en>

  Solution description:

    Greedy
    The first and the last are always possible.
    Simulate from left to right, if possibile to cut left do it,
    else if possible to cut down do it and "swap" tree i with i+1

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
#include <cmath>

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<int> X(N), H(N);
  for(int i=0; i<N; i++) std::cin >> X[i] >> H[i];

  int sol = std::min(N, 2); // always the first on the left and last on right

  for(int i=1; i<N-1; i++)
  {
    if(X[i]-X[i-1] > H[i]) sol++; // fall on left
    else if(X[i+1]-X[i] > H[i])
    {
      sol++;
      X[i] += H[i]; // "swap" tree
    }
  }

  std::cout << sol << std::endl;

  return 0;
}
