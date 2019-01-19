/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/contest/86/problem/D>

  Solution description:

    Just an implementation of mo's algorithm with bucket size of 512

    (Executime time very near to ~5sec, if TLE submit again :P)

    ****************************************************************
    * SEE: <https://codeforces.com/contest/86/submission/48570332> *
    * FOR AN ACCEPTED SOLUTION                                     *
    ****************************************************************

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
  // Read input
  int N, T, bucket=1;
  scanf("%d %d", &N, &T);
  std::vector<long long int> V(N);
  std::vector<long long int> freq(1e6+1, 0ll);
  std::vector<long long int> sol(T, 0ll);
  std::vector<std::array<int, 3>> Q(T);
  for(int i=0; i<N; i++) scanf("%I64d", &V[i]);
  for(int i=0; i<T; i++) scanf("%I64d %I64d", &Q[i][0], &Q[i][1]);
  for(int i=0; i<T; i++) Q[i][0]--, Q[i][2] = i;

  while(bucket*bucket < N) bucket++;

  // Sort queries
  std::sort(Q.begin(), Q.end(), [&](const std::array<int, 3> X, const std::array<int, 3> Y)
  {
    return (X[0]/bucket != Y[0]/bucket) ? X[0] < Y[0] : X[1] < Y[1];
  });

  // execute queries
  int cl = 0, cr = 0;   // current left, current right
  long long int sum = 0;// current sum

  for(int i=0; i<T; i++)
  {
    // Remove on left
    while(cl<Q[i][0])
    {
      int el = V[cl];
      sum -= freq[V[cl]]*freq[V[cl]]*el;
      freq[el]--;
      sum += freq[V[cl]]*freq[V[cl]]*el;
      cl++;
    }

    // Add on left
    while(cl>Q[i][0])
    {
      cl--;
      int el = V[cl];
      sum -= freq[V[cl]]*freq[V[cl]]*el;
      freq[el]++;
      sum += freq[V[cl]]*freq[V[cl]]*el;
    }

    // Remove on right
    while(cr>Q[i][1])
    {
      cr--;
      int el = V[cr];
      sum -= freq[V[cr]]*freq[V[cr]]*el;
      freq[el]--;
      sum += freq[V[cr]]*freq[V[cr]]*el;
    }

    // Add on right
    while(cr<Q[i][1])
    {
      int el = V[cr];
      sum -= freq[V[cr]]*freq[V[cr]]*el;
      freq[el]++;
      sum += freq[V[cr]]*freq[V[cr]]*el;
      cr++;
    }

    sol[Q[i][2]] = sum;
  }

  // Print solutions
  for(int i=0; i<T; i++) printf("%I64d\n", sol[i]);

  return 0;
}
