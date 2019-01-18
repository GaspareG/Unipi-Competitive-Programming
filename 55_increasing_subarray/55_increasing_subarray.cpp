/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text12062018.pdf>

  Solution description:

    Split vector if contiguous sequence of increasing subarray.
    We can obtain the solution in 3 way:

    1) simplier, min(N, longest increasing subarray+1)

    2) merge two consecutive contiguous subarray if we can change
       the last element of first or first element of second

    3) merge three consecutive contiguous subarray if the second is large 1
      and the difference between the first of last and the last of first is greater than 1

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

  int N, sol = 0;
  std::cin >> N;
  std::vector<int> V(N);
  std::vector<std::array<int, 2>> pos;

  for(int i=0; i<N; i++) std::cin >> V[i];
  for(int i=0; i<N; i++)
  {
    int j = i;
    while(j+1 < N && V[j] < V[j+1]) j++;
    pos.push_back({i, j});
    sol = std::max(sol, (j-i+1));
    i = j;
  }

  /*******************************************************************/
  // way 1: change one before or after the longest sequence
  //    [9] [1 2 3 4]
  //    [1 2 3 4] [9]
  sol = std::min(sol+1, N);

  /*******************************************************************/
  // way 2: merge V[pos[i]] and V[pos[i+1]] by changing V[pos[i][1]] or V[pos[i+1][0]]
  for(int i=0; i<pos.size()-1; i++)
  {
    // Change last of pos[i]
    if(pos[i][0] != pos[i][1])
    {
      // [... w x] [y z ...] change x s.t. w < x < y
      if(V[pos[i+1][0]] - V[pos[i][1]-1] > 1)
        sol = std::max(sol, pos[i+1][1]-pos[i][0]+1);
    }

    // Change first of pos[i]
    if(pos[i+1][0] != pos[i+1][1])
    {
      // [... w x] [y z ...] change y s.t. x < y < z
      if(V[pos[i+1][0]+1] - V[pos[i][1]] > 1)
        sol = std::max(sol, pos[i+1][1]-pos[i][0]+1);
    }
  }

  /*******************************************************************/
  // way 3: merge V[pos[i]] + V[pos[i+1]] + V[pos[i+2]]
  //   (if pos[i+1][0] == pos[i+1][1]) by changing V[pos[i+1][0]]
  // [1 2 3 4] [1] [6 7 8 9]
  for(int i=0; i<pos.size()-2; i++)
  {
    // pos[i+1] greater than 1
    if(pos[i+1][0] != pos[i+1][1]) continue;
    // No space for changing V[pos[i+1]]
    if(V[pos[i+2][0]] - V[pos[i][1]] <= 1) continue;
    // Merge V[pos[i][0]..pos[i+2][1]]
    sol = std::max(sol, pos[i+2][1]-pos[i][0]+1);
  }

  std::cout << sol << std::endl;

  return 0;
}
