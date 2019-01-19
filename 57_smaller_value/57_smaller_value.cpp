/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14012019.pdf>

  Solution description:

    Sort input vector by increasing value (and keep original index)

    Use a fenwick tree to keep the sum of inserted indexes.

    For each X = 0..N-1
      Add +1 to the index of elements in vector with value = X
      For each query (i,j) with value X:
        solution = ft.query(i,j)

    Sorting vector: O(N*log(N))
    Inserting once each element in ft: O(N*log(N))
    Queries ft once per query: O(M*log(N))
    ----------------------------------------
    Total: O((N+M)*log(N))

  Time  complexity: O((N+M)*log(N))
  Space complexity: O(N+M)

  Where:
  - N is the vector size
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

  int N, M, qi, qj, qx;
  std::cin >> N >> M;

  std::vector<std::array<int, 2>> V(N); // [V, idx]
  std::vector<std::vector<std::array<int, 3>>> Q(N); // Q[X] = queries[i, j, idx]

  std::vector<int> sol(M, 0);
  struct fenwick_tree<int> ft(N);

  // Read input vector
  for(int i=0; i<N; i++) std::cin >> V[i][0];
  for(int i=0; i<N; i++) V[i][1] = i;

  // Read queries
  for(int i=0; i<M; i++)
  {
    std::cin >> qi >> qj >> qx;
    Q[std::min(N-1, qx)].push_back({qi, qj, i});
  }

  // sort V: O(N*log(N))
  std::sort(V.begin(), V.end()); // sort by value

  int v=0;
  for(int X=0; X<N; X++)
  {
    // add N values in ft: O(N*log(N))
    while(v < N && V[v][0] <= X) ft.add(V[v++][1], +1);

    // For each query of X
    for(auto [i, j, idx] : Q[X])
      // query m times ft: O(M*log(N))
      sol[idx] = ft.sum(j) - ((i > 0) ? ft.sum(i-1) : 0);
  }

  for(int i=0; i<M; i++) std::cout << sol[i] << std::endl;

  return 0;
}
