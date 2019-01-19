/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/x-total-shapes/0>

  Solution description:

    Simply a DFS over the matrix to count the CCs.

  Time  complexity: O(T*N*M)
  Space complexity: O(N*M)

  Where:
  - T is the number of test cases
  - N is the height of the matrix
  - M is the width of the matrix
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

void dfs(const std::vector<std::string> &S,
         std::vector<std::vector<bool>> &seen, int i, int j)
{
  if(i < 0 || j < 0) return;
  if(i >= S.size() || j >= S[0].size() ) return;
  if(seen[i][j] || S[i][j] == 'O') return;

  seen[i][j] = true;
  dfs(S, seen, i-1, j);
  dfs(S, seen, i+1, j);
  dfs(S, seen, i, j-1);
  dfs(S, seen, i, j+1);
}

void solve()
{
  int N, M, cc=0;
  std::cin >> N >> M;
  std::vector<std::string> S(N);
  std::vector<std::vector<bool>> seen(N, std::vector<bool>(M, false));

  for(int i=0; i<N; i++) std::cin >> S[i];

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      if(S[i][j] == 'X' && !seen[i][j])
        cc++, dfs(S, seen, i, j);

  std::cout << cc << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
