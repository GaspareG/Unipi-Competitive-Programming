/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <url>

  Solution description:


  Time  complexity: O()
  Space complexity: O()

  Where:

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
  std::vector<std::array<long long int, 2>> LU;
  std::vector<long long int> ST;

  SegmentTree(int n)
  {
    N = n;
    ST.resize(N, 0);
    LU.resize(N*4, {-1, -1});
    for(int i=0; i<N; i++) ST[i] = -i;
  }

  void update(int x, int y, int k){ update(1, 0, N-1, x, x+k-1, y, y+k-1); }

  // [bs, be] = [as, ae]
  void update(int idx, int s, int e, int as, int ae, int bs, int be)
  {
    if(e < be)
    {
      int diffe = be-e;
      be -= diffe;
      ae -= diffe;
    }

    if(s > bs)
    {
      int diffs = s-bs;
      bs -= diffs;
      as -= diffs;
    }

    std::cout << idx << "["<< s << ", " << e << "] [" << as << ", " << ae << "] [" << bs <<", " << be << "]" << std::endl;

    if(s > e || s > be || e < bs){ std::cout << "\tCLOSE" << std::endl; return; }


    if(s == e)
    {
      ST[s] = as;
      return;
    }

    if(s >= bs && e <= be)
    {
      LU[idx] = {as, ae};
      return;
    }

    int  m = ( s+ e)/2;

    update(2*idx  , s  , m, as, ae, bs, be);
    update(2*idx+1, m+1, e, as, ae, bs, be);
  }

  long long int query(int x)
  {
    return query(1, 0, N-1, x);
  }

  long long int query(int idx, int s, int e, int x)
  {
    if(s > x || e < x) return N+1;

    if(!(LU[idx][0] == -1 && LU[idx][1] == -1))
    {
      if(s == e)
      {
        ST[idx] = LU[idx][0];
      }
      else if(s+1 == e)
      {
        ST[2*idx  ] = LU[idx][0];
        ST[2*idx+1] = LU[idx][1];
      }
      else
      {
        int mlu = (LU[idx][0]+LU[idx][1])/2;
        LU[2*idx  ] = {LU[idx][0], mlu};
        LU[2*idx+1] = {mlu+1, LU[idx][1]};
      }
      LU[idx] = {-1, -1};
    }

    if(s == e) return ST[s];

    int m = (s+e)/2;
    int l = query(2*idx  , s  , m, x);
    int r = query(2*idx+1, m+1, e, x);

    return (l == N+1) ? r : l;
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N, M;
  int t, x, y, k;
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
      int idx = st.query(++x);
      std::cout << (idx < 0 ? B[-idx] : A[idx]) << std::endl;
    }
  }
  return 0;
}
