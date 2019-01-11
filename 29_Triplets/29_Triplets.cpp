/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14022018.pdf>

  Solution description:

    Fixed and index j of the vector the number of couple (i,k)
    s.t. V[i] < V[j] < V[k] is (left_count) * (right_count)
    where left_count is the number of elements in V[0..i-1] less than V[i]
    and right_count is the number of elements in V[i+1...N-1] greater than V[i].

    A simple way to obtain their value is to simply iteratore over all the vector and count,
    this lead to a O(N²) solution).

    To lower the complexity we can use two fenwick tree to speed-up the two queries,
    one for the left part and one for the right part of the array.

    At the beggining all the elements are summed up to the right fenwick tree,
    we iterate i from 0 to N-1, count the number of triplets by quering the two fenwick tree,
    add V[i] to the left fenwick tree and remove V[i] from the right fenwick tree.

    The solution is the sum of all the triplets for each i.
    We need O(N) space to store the two fenwick tree and O(N*log2(N)) time as we have to do
    N queries to the two fenwick tree at the cost of O(log2(N)) each.

  Time  complexity: O(N*log2(N))
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
#include "../00_utility/fenwick.hpp"

int main()
{
  int N;
  long long int sol = 0ll;

  std::cin >> N;
  std::vector<int> V(N);

  // Read the input vector
  for(int i=0; i<N; i++) std::cin >> V[i];

  // Create the two fenwick trees
  struct fenwick_tree<int> left(N);
  struct fenwick_tree<int> right(N);

  // Fill the right fenwick tree
  for(int i=0; i<N; i++) right.add(V[i], 1);

  // For each element in vector
  for(int i=0; i<N; i++)
  {
    // Count the number of element < V[i] in [0, i)
    int leftCount = left.sum(V[i]-1);
    // Count the number of element > V[i] in (i, N)
    int rightCount = right.sum(N) - right.sum(V[i]);

    // The number of triplets for V[i] is leftCount*rightCount
    sol += leftCount * rightCount;

    // Add V[i] to the left fenwick tree
    left.add(V[i], 1);
    // Add V[i] to the right fenwick tree
    right.add(V[i], -1);
  }

  // Print the solution
  std::cout << sol << std::endl;

  return 0;
}

