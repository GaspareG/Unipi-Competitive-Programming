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

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  std::vector<int> V(N);
  for(int i=0; i<N; i++) std::cin >> V[i];
  for(int i=0; i<M; i++)
  {
    int a, b, x, sol=0;
    std::cin >> a >> b >> x;
    for(a; a<=b; a++)
      if(V[a] <= x)
        sol++;
    std::cout << sol << std::endl;
  }
  return 0;
}
