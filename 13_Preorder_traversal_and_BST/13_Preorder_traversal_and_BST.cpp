/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0>

  Solution description:

    The root is the first element.
    Find the first index such that its value is greater than the root,
    the elements before the index are the left subtree, the elements after the index
    are the right subtree.

    We check if all the elements in the right subtree are greater than the root,
    We check the left substree,
    We check the right subtree.

    If all the properties are check then true, otherwise false.

  Time  complexity: O(N^2)
  Space complexity: O(N)

  Where:
  - N is the size of input vector
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

int check(const std::vector<int> &V, int l, int r)
{
  if(l >= r) return 1;

  // Find first value i such that V[i] > V[root]
  int i;
  for(i=l+1; i<r; i++)
    if(V[i] > V[l])
      break;

  // Check left part
  if(!check(V, l+1, i)) return 0;

  // Check if right part is consistent
  for(int j=i; j<r; j++)
    if(V[l] >= V[j])
      return 0;

  return check(V, i, r);
}

void solve()
{
  int N;
  std::cin >> N;
  std::vector<int> V(N);
  for(int i=0; i<N; i++) std::cin >> V[i];
  std::cout << check(V, 0, V.size()) << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();
  return 0;
}
