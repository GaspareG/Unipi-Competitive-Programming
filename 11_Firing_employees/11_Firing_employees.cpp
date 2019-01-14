/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/firing-employees/0>

  Solution description:

    Precompute primes using the sieve of eratosthenes (?).
    Create the tree from the given rank, find the root (the one with rank 0).
    Start a dfs from root to leaves to calculate the heights of the nodes.

    Count how many i+rank[i] are primes.

  Time  complexity: O(T*N)
  Space complexity: O(N)

  Where:
  - T is the number of test cases
  - N is the number of employes
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

std::vector<bool> primes(100010, true);

void sieve()
{
  long long int N = static_cast<long long int>(primes.size()-1);

  primes[0] = primes[1] = false;

  for(long long int i=2ll; i*i<=N; i++)
  {
    if(!primes[i]) continue;
    for(long long int j=i*i; j<=N; j+=i)
      primes[j] = false;
  }
}

void dfs(const std::vector<std::vector<int>> &T, std::vector<int> &rank, int u, int r)
{
  rank[u] = r;
  for(int v : T[u])
    dfs(T, rank, v, r+1);
}

void solve()
{
  int N, root=0, sol=0, x;
  std::cin >> N;
  std::vector<std::vector<int>> T(N+1);
  std::vector<int> rank(N+1, 0);

  for(int i=1; i<=N; i++)
  {
    std::cin >> x;
    if(x == 0) root = i;
    else T[x].push_back(i);
  }

  dfs(T, rank, root, 0);
  rank[root] = -root;

  for(int i=1; i<=N; i++)
    sol += primes[i+rank[i]];

  std::cout << sol << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  sieve();

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
