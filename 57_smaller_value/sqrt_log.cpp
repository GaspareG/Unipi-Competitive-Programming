/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14012019.pdf>

  Solution description:

    MO's algorithm + fenwick tree for counting items

  Time  complexity: O((N+M)*sqrt(N)*log(N))
  Space complexity: O(N+M)

  Where:
  - N is the size of the input vector
  - M is the number of queries

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
#include "../00_utility/fenwick.hpp"

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N, M, sq=1;

  std::cin >> N >> M;
  std::vector<int> V(N);
  std::vector<int> sol(M, 0);
  std::vector<std::array<int, 4>> Q(M);
  struct fenwick_tree<int> ft(N);

  for(int i=0; i<N; i++) std::cin >> V[i];
  for(int i=0; i<M; i++) std::cin >> Q[i][0] >> Q[i][1] >> Q[i][2];
  for(int i=0; i<M; i++) Q[i][0]--, Q[i][3] = i;

  while(sq*sq < N) sq++;
  std::sort(Q.begin(), Q.end(), [sq](const std::array<int, 4> X, const std::array<int, 4> Y)
  {
    return (X[0]/sq != Y[0]/sq) ? X[0] < Y[0] : X[1] < Y[1];
  });

  int cl = 0, cr = 0;

  for(int i=0; i<M; i++)
  {
    while(cl<Q[i][0]) ft.add(V[cl++], -1); // Remove on left
    while(cl>Q[i][0]) ft.add(V[--cl], +1); // Add on left
    while(cr>Q[i][1]) ft.add(V[--cr], -1); // Remove on right
    while(cr<Q[i][1]) ft.add(V[cr++], +1); // Add on right
    sol[Q[i][3]] = ft.sum(Q[i][2]);
  }

  for(int i=0; i<M; i++) std::cout << sol[i] << std::endl;

  return 0;
}
