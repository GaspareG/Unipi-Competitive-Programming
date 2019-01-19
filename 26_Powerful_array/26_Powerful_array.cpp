/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/contest/86/problem/D>

  Solution description:

    Just an implementation of mo's algorithm with bucket size of 512

    (Executime time very near to ~5sec, if TLE submit again :P)

  Time  complexity: O(N*log(N) + (N+Q)*sqrt(N))
  Space complexity: O(N+Q+max|V[i]|)

  Where:
  - N is the size of the vector
  - Q is the number of queries
  - V is the input vector

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

  // Read input
  int N, T, bucket=512;
  std::cin >> N >> T;
  std::vector<long long int> V(N);
  std::vector<long long int> freq(1e6+1, 0ll);
  std::vector<long long int> sol(T, 0ll);
  std::vector<std::array<int, 3>> Q(T);
  for(int i=0; i<N; i++) std::cin >> V[i];
  for(int i=0; i<T; i++) std::cin >> Q[i][0] >> Q[i][1];
  for(int i=0; i<T; i++) Q[i][0]--, Q[i][2] = i;

  // Sort queries
  std::sort(Q.begin(), Q.end(), [&](const std::array<int, 3> X, const std::array<int, 3> Y)
  {
    return (X[0]/bucket != Y[0]/bucket) ? X[0] < Y[0] : X[1] < Y[1];
  });

  // execute queries
  int cl = 0, cr = 0;   // current left, current right
  long long int sum = 0;// current sum

  auto update = [&](long long int el, long long int d)
  {
    sum -= freq[el]*freq[el]*el;
    freq[el] += d;
    sum += freq[el]*freq[el]*el;
  };

  for(int i=0; i<T; i++)
  {
    while(cl<Q[i][0]) update(V[cl++], -1ll); // Remove on left
    while(cl>Q[i][0]) update(V[--cl], +1ll); // Add on left
    while(cr>Q[i][1]) update(V[--cr], -1ll); // Remove on right
    while(cr<Q[i][1]) update(V[cr++], +1ll); // Add on right
    sol[Q[i][2]] = sum;
  }

  // Print solutions
  for(int i=0; i<T; i++) std::cout << sol[i] << std::endl;

  return 0;
}
