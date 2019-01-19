/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://codeforces.com/problemset/problem/342/E>

  Solution description:

    Simple centroid decomposition

  Time  complexity: O((N+Q)*log(N))
  Space complexity: O(N)

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

int N, M, t, v;
std::vector<std::set<int>> T;           // Tree
std::vector<int> H;                     // Height of node i
std::vector<int> S;                     // Size of substree i
std::vector<int> P;                     // Parent in centroid of node i
std::vector<int> D;                     // Distance to nearest from node i
std::vector<std::array<int, 20>> Anc;   // 2^k-th ancestor of node i

// Compute height and direct ancester for each node
void dfs(int u, int p, int h)
{
  H[u] = h;
  Anc[u][0] = p;
  for(int v : T[u])
    if(v != p)
      dfs(v, u, h+1);
}

// Compute ancestors at distance 2^h for each node
void ancestors()
{
  for(int h=1; h<20; h++)
    for(int u=0; u<N; u++)
      Anc[u][h] = (Anc[u][h-1] == -1) ? -1 : Anc[Anc[u][h-1]][h-1];
}

// Find lowest common ancest between u and v
int lca(int u, int v)
{
  // Same node, lca itself
  if(u == v) return u;
  // We keep u as the highest
  if(H[u] < H[v]) return lca(v, u);

  // Bring u at same height of v
  int k = 19;
  while(H[u] - H[v] > 0)
  {
    // Find biggest step of 2^k we can do then jump
    while(H[u] - H[v] < (1 << k)) k--;
    u = Anc[u][k];
  }

  // Move at same speed untile same node (LCA(u,v))
  k = 19;
  while(u != v)
  {
    // Find biggest step of 2^k we can do then jump
    while(k > 0 && Anc[u][k] == Anc[v][k]) k--;
    u = Anc[u][k];
    v = Anc[v][k];
  }

  return u;
}

// Size of shortest path between u and v
int dist(int u, int v){ return H[u]+H[v]-2*H[lca(u, v)]; }

// Find centroid of subtree u
int centroid(int u, int p, int s)
{
  for(int v : T[u])
    if(v != p && S[v] > s/2)
      return centroid(v, u, s);
  return u;
}

// Compute size of substree
int size(int u, int p)
{
  S[u] = 1;
  for(int v : T[u])
    if(v != p)
      S[u] += size(v, u);
  return S[u];
}

// Centroid decomposition
void decomposition(int u, int p)
{
  // Find centroid and update parent
  int c = centroid(u, -1, size(u, -1));
  P[c] = p;

  // For each adjacent to centroid
  for(int v : T[c])
  {
    T[v].erase(c);      // Remove the edge
    decomposition(v, c);// Recurse
  }

  T[c].clear();         // Remove edges
}

// Update from u to root of the centroid decomposition
void update(int u)
{
  int v = u;
  while(v != -1)
  {
    D[v] = std::min(D[v], dist(u, v));
    v = P[v];
  }
}

// Query from u to root of the centroid decomposition
int query(int u)
{
  int v = u;
  int sol = 1e6;
  while(v != -1)
  {
    sol = std::min(sol, D[v]+dist(u, v));
    v = P[v];
  }
  return sol;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  // Read input
  std::cin >> N >> M;

  // Resize vectors to right size
  T.resize(N);
  H.resize(N, 0);
  S.resize(N, 0);
  P.resize(N, 0);
  D.resize(N, 1e6);
  Anc.resize(N);

  for(int i=0; i<N-1; i++)
  {
    std::cin >> t >> v;
    t--;
    v--;
    T[t].insert(v);
    T[v].insert(t);
  }

  dfs(0, -1, 0);        // Initial dfs
  ancestors();          // Calculate ancestors distants 2^k
  decomposition(0, -1); // Centroid decomposition
  update(0);            // Only 0 is initially painted

  // Execute queries and updates
  for(int i=0; i<M; i++)
  {
    std::cin >> t >> v;
    v--;
    if(t == 1) update(v);
    else std::cout << query(v) << std::endl;
  }

  return 0;
}
