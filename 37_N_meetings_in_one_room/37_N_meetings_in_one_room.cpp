/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0>

  Solution description:

    Sort by finish time, the first is always choosen.
    Keep a pointer last with last choosen, select the first j
    if end[last] <= start[j] and then update last = j

  Time  complexity: O(T*N*log(N))
  Space complexity: O(N)

  Where:
  - T is the number of test cases
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

void solve()
{
  int N;

  std::cin >> N;
  std::vector<std::array<int, 3>> V(N); // <end, start, idx>

  for(int i=0; i<N; i++) std::cin >> V[i][1];
  for(int i=0; i<N; i++) std::cin >> V[i][0];
  for(int i=0; i<N; i++) V[i][2] = i+1;

  std::sort(V.begin(), V.end());
  std::cout << V[0][2];

  for(int last=0,i=1; i<N; i++)
  {
    if(V[last][0] <= V[i][1])
    {
      std::cout << " " << V[i][2];
      last = i;
    }
  }

  std::cout << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
