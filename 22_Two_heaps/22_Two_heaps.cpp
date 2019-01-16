/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/353/B?locale=en>

  Solution description:

    Count the frequencies of each number.
    Assign the elements with freq = 1 to alternate heaps,
    ther other ones split equals among the two.

  Time  complexity: O(N)
  Space complexity: O(N)

  Where:
  - N is the number of cubes

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
  std::vector<int> V(2*N);
  for(int i=0; i<2*N; i++) std::cin >> V[i];

  // Count frequencies
  std::vector<int> count(100, 0);
  for(int v : V) count[v]++;

  // Two heaps
  std::array<int, 100> H[2];
  std::fill(H[0].begin(), H[0].end(), 0);
  std::fill(H[1].begin(), H[1].end(), 0);

  // Put the numbers with count=1 in alternate heaps
  int bucket = 1;
  for(int i=0; i<100; i++)
    if(count[i] == 1)
      H[bucket=(1-bucket)][i]++;

  std::array<int, 2> dim = {0, 0};

  // Split the numbers with count>1 among the two heaps
  for(int i=0; i<100; i++)
  {
    if(count[i] != 1)
    {
      H[0][i] += count[i] / 2;
      H[1][i] += count[i] / 2;
      // If odd put in alternate heaps
      if(count[i] % 2 == 1)
        H[bucket=(1-bucket)][i]++;
    }

    // Size of the heaps
    dim[0] += H[0][i] > 0;
    dim[1] += H[1][i] > 0;
  }

  std::cout << (dim[0]*dim[1]) << std::endl;

  // Print the assignment among the two heaps
  for(int i=0; i<2*N; i++)
  {
    std::cout << (H[0][V[i]] > 0 ? 1 : 2) << " ";
    H[(H[0][V[i]] > 0 ? 0 : 1) ][V[i]]--;
  }

  std::cout << std::endl;

  return 0;
}
