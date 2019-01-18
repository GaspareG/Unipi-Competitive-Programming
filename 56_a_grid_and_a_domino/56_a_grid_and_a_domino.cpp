/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text06072018.pdf>
           <https://codeforces.com/problemset/problem/611/C?locale=en>

  Solution description:

    Transform all the coordinates in 0-based.
    Use an approach like the DP for calculating the sum of rectangle in a matrix in O(1).

    Calculate the matrix Gh, Gv which contains the solutions for horizontal and vertical pieces.
    Then each query can be answered in O(1)

  Time  complexity: O(W*H+Q)
  Space complexity: O(W*H)

  Where:
  - W is the width of the matrix
  - H is the height of the matrix
  - Q is the number of queries
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

  int N, M, Q, sol;
  int r1, c1, r2, c2;
  std::cin >> N >> M;
  std::vector<std::string> S(N);
  std::vector<std::vector<int>> Gh(N, std::vector<int>(M, 0));
  std::vector<std::vector<int>> Gv(N, std::vector<int>(M, 0));

  for(int i=0; i<N; i++) std::cin >> S[i];

  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      if(S[i][j] == '#') continue;
      if(j+1 < M && S[i][j+1] == '.') Gv[i][j]++;
      if(i+1 < N && S[i+1][j] == '.') Gh[i][j]++;
    }
  }

  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      if(i > 0)
      {
        Gh[i][j] += Gh[i-1][j];
        Gv[i][j] += Gv[i-1][j];
      }
      if(j > 0)
      {
        Gh[i][j] += Gh[i][j-1];
        Gv[i][j] += Gv[i][j-1];
      }
      if(i > 0 && j > 0)
      {
        Gh[i][j] -= Gh[i-1][j-1];
        Gv[i][j] -= Gv[i-1][j-1];
      }
    }
  }

  auto quad = [](const std::vector<std::vector<int>> &M, int r1, int c1, int r2, int c2)
  {
    if (r1 > r2 || c1 > c2) return 0;
    int sol = M[r2][c2];
    if (r1 > 0) sol -= M[r1-1][c2];
    if (c1 > 0) sol -= M[r2][c1-1];
    if (r1 > 0 && c1 > 0) sol += M[r1-1][c1-1];
    return sol;
  };

  std::cin >> Q;
  for(int i=0; i<Q; i++)
  {
    std::cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;
    sol = 0;
    sol += quad(Gv, r1, c1, r2, c2-1);
    sol += quad(Gh, r1, c1, r2-1, c2);
    std::cout << sol << std::endl;
  }

  return 0;
}
