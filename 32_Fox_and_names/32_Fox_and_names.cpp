/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/510/C?locale=en>

  Solution description:

    Create a graph (char -> char), we put an edge for each first mismatch in two
    consecutive string. (Es Pluto/Pippo -> l-i).

    We start a dfs from each unvisited char, If we found a cycle then impossibile
    to find an alphabet, otherwise we put the current char in a stack and at the end
    print the stack from top to bottom.

  Time  complexity: O(N)
  Space complexity: O(N)

  Where:
  - N is the number of names
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


bool dfs(const std::vector<std::vector<int>> &G, std::vector<int> &seen, std::stack<int> &alpha, int idx)
{

  if(seen[idx] == 0)
  {
    seen[idx] = 1;

    for(int to : G[idx])
      if(!dfs(G, seen, alpha, to))
        return false;

    alpha.push(idx);
    seen[idx] = 2;
  }
  else if(seen[idx] == 1)
    return false;

  return true;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N;
  bool check = true;

  std::cin >> N;
  std::vector<std::string> V(N);
  std::vector<std::vector<int>> G(26); // graph
  std::vector<int> seen(26, 0);
  std::stack<int> alfa;

  for(int i=0, j=0; i<N; i++)
  {
    std::cin >> V[i];
    if(i == 0) continue;

    size_t l = std::min(V[i].size(), V[i-1].size());
    for(j=0; j<l; j++)
    {
      if(V[i][j] != V[i-1][j])
      {
        G[V[i-1][j]-'a'].push_back(V[i][j]-'a');
        break;
      }
    }
    if(j == l && V[i].size() < V[i-1].size())
    {
      std::cout << "Impossible" << std::endl;
      return 0;
    }
  }

  for(int i=0; i<26; i++) if(seen[i] == 0) check &= dfs(G, seen, alfa, i);

  if(!check)
  {
    std::cout << "Impossible" << std::endl;
  }
  else
  {
    while(!alfa.empty())
    {
      std::cout << static_cast<char>(alfa.top()+'a');
      alfa.pop();
    }
    std::cout << std::endl;
  }
  return 0;
}
