/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text23012018.pdf>

  Solution description:

  Just use a segment tree with range update and lazy propagation.
  A little bit of tricks are needed: the range tree store the index of elements, not number themselves.

  The leafs in the tree contains -idx if contains B[idx] or idx it contains A[idx] (we transform
  queries from 0-based to 1-based to handle the case for idx=0).

  The internal nodes don't exists, the tree contains only the information regarding to the lazy update.

  Time  complexity: O(N+Q*log(N))
  Space complexity: O(N)

  Where:
  - N is the size of the vector
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

struct SegmentTree
{

  int N;
  int invalid;
  std::vector<std::array<long long int, 2>> LU;
  std::vector<long long int> ST;
  std::array<long long int, 2> relaxed = {-1, -1};

  SegmentTree(int n)
  {
    N = n;
    invalid = N+1;
    ST.resize(N, 0ll);
    LU.resize(N*4, relaxed);
    std::generate(ST.begin(), ST.end(), [n = 0ll] () mutable { return n--; });
  }

  void propagate(int idx, int s, int e)
  {
    // Already propagated
    if(LU[idx] == relaxed) return;

    // Leaf
    if(s == e) ST[s] = LU[idx][0];
    // Father of leaf
    else if(s+1 == e)
    {
      ST[s] = LU[idx][0];
      ST[e] = LU[idx][1];
    }
    // Internal node
    else
    {
      int m = (s+e)/2;
      LU[2*idx  ] = {LU[idx][0]        , LU[idx][0]+(m-s)};
      LU[2*idx+1] = {LU[idx][0]+(m-s)+1, LU[idx][1]};
    }
    // Set node as relaxed
    LU[idx] = relaxed;
  }

  // Update
  void update(int x, int y, int k){ update(1, 0, N-1, x, x+k-1, y, y+k-1); }
  void update(int idx, int s, int e, int as, int ae, int bs, int be)
  {
    // If outside of range exit
    if(s > e || s > be || e < bs) return;

    // Propagate the update
    propagate(idx, s, e);

    // Leaf, direct update
    if(s == e)
    {
      ST[s] = as + (s-bs);
      return;
    }

    // If totally in range, set the laxy update
    if(s >= bs && e <= be)
    {
      int diff = (s-bs);
      LU[idx] = {as+diff, as+diff+(e-s)};
      return;
    }

    // Split to child
    int m = (s+e)/2;
    update(2*idx+0, s+0, m, as, ae, bs, be);
    update(2*idx+1, m+1, e, as, ae, bs, be);
  }

  // Query
  long long int query(int x){  return query(1, 0, N-1, x); }
  long long int query(int idx, int s, int e, int x)
  {
    // out of range
    if(s > x || e < x) return invalid;

    // propagate the update
    propagate(idx, s, e);

    // if leaf return the index
    if(s == e) return ST[s];

    // Split in two queries
    int m = (s+e)/2;
    int l = query(2*idx+0, s+0, m, x);
    int r = query(2*idx+1, m+1, e, x);

    // Return the valid index
    return (l == invalid) ? r : l;
  }

};

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N, M;
  int t, x, y, k, idx;

  std::cin >> N >> M;
  std::vector<int> A(N+1), B(N+1);
  struct SegmentTree st(N+1);

  for(int i=1; i<=N; i++) std::cin >> A[i];
  for(int i=1; i<=N; i++) std::cin >> B[i];

  for(int i=0; i<M; i++)
  {
    std::cin >> t;
    if(t == 1)
    {
      std::cin >> x >> y >> k;
      st.update(++x, ++y, k);
    }
    else
    {
      std::cin >> x;
      idx = st.query(++x);
      std::cout << (idx < 0 ? B[-idx] : A[idx]) << std::endl;
    }
  }

  return 0;
}
