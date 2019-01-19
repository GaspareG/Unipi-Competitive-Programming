/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/contest/375/problem/D>

  Solution description:

    Mo's algorithm over a tree using color frequencies count.

  Time  complexity: O((N+Q)*sqrt(Q))
  Space complexity: O(N+Q)

  Where:
  - N is the size of the tree
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

std::vector<int> C;                 // Colors
std::vector<std::vector<int>> T;    // Tree edges
std::vector<std::array<int, 4>> Q;  // Queries [start, end, k, idx]
std::vector<int> freq;              // frequency
std::vector<int> freqK;             // frequency of k
std::vector<int> sol;               // query solutions
std::vector<int> dfsIn;             // Index of enter dfs
std::vector<int> dfsOut;            // Index of exit dfs
std::vector<int> lin;               // Linearize of dfs
int dfsIdx = 0;                     // Dfs index count

void dfs(int u, int p)
{
  dfsIn[u] = ++dfsIdx;
  lin[dfsIdx] = C[u];
  for(int v : T[u]) if(v != p) dfs(v, u);
  dfsOut[u] = dfsIdx;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N, M, bucket = 512;
  std::cin >> N >> M;

  // Allocate memory
  C.resize(N+1);
  T.resize(N+1);
  Q.resize(M);
  sol.resize(M+1, 0);
  freq.resize(1e5+1, 0);
  freqK.resize(1e5+1, 0);
  dfsIn.resize(N+1, 0);
  dfsOut.resize(N+1, 0);
  lin.resize(N+1, 0);

  // Read input
  for(int i=0; i<N; i++) std::cin >> C[i];
  for(int i=1; i<N; i++)
  {
    int x, y;
    std::cin >> x >> y;
    x--; y--;
    T[x].push_back(y);
    T[y].push_back(x);
  }

  // Start dfs from root 0
  dfs(0, -1);

  // Read and create queries
  for(int i=0; i<M; i++)
  {
    int v, k;
    std::cin >> v >> k;
    v--;
    Q[i][0] = dfsIn[v];
    Q[i][1] = dfsOut[v];
    Q[i][2] = k;
    Q[i][3] = i;
  }

  // Sort queries by bucket
  std::sort(Q.begin(), Q.end(), [&](const std::array<int, 4> X, const std::array<int, 4> Y)
  {
    return (X[0]/bucket != Y[0]/bucket) ? X[0] < Y[0] : X[1] < Y[1];
  });

  // Current left and right
  int cl = Q[0][0];
  int cr = cl-1;

  auto add = [&](int pos)     // Increment window
  {
    freq[lin[pos]]++;
    freqK[freq[lin[pos]]]++;
  };

  auto remove = [&](int pos)  // Decrement window
  {
    freqK[freq[lin[pos]]]--;
    freq[lin[pos]]--;
  };

  for(int i=0; i<M; i++)
  {
    while(cl > Q[i][0])    add(--cl); // Add from left
    while(cl < Q[i][0]) remove(cl++); // Remove from left
    while(cr < Q[i][1])    add(++cr); // Add from right
    while(cr > Q[i][1]) remove(cr--); // Remove from right
    sol[Q[i][3]] = freqK[Q[i][2]];
  }

  // Print sorted solution
  for(int i=0; i<M; i++) std::cout << sol[i] << std::endl;

  return 0;
}
