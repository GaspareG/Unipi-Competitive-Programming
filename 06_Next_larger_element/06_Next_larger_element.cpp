/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/next-larger-element/0>

  Solution description:

    We use a stack to keep the next greater element.
    At each step we pop the stack until is empty or the top is greater than
    the current element. the solution for the i-th step is the top of the stack
    or -1 if it is empty. At the end of each step we push the current element.

  Time  complexity: O(T*N)
  Space complexity: O(N)

  Where:
  - T is the number of test cases
  - N is the size of the input vector
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

void solve()
{
  int N;
  std::cin >> N;
  std::vector<int64_t> V(N);
  std::vector<int64_t> sol(N);
  std::stack<int64_t> S;
  for(int i=0; i<N; i++) std::cin >> V[i];

  for(int i=N-1; i>=0; i--)
  {
    while(!S.empty() && S.top() < V[i]) S.pop();
    sol[i] = S.empty() ? -1 : S.top();
    S.push(V[i]);
  }

  for(auto s : sol) std::cout << s << " ";
  std::cout << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
