/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0>

  Solution description:

  Keep a sliding window of size K,
  for each subarray of size K we want to know the max value of its element,
  a naive way to do this is to iterate over the window, this lead to a O(N²) solution.

  To speed up the solution we can use a MaxQueue (variant of the MinQueue):
  a data struct that provide a push/pop function of an element in a queue and
  a getMax function, all in constant time.

  Time  complexity: O(T*N)
  Space complexity: O(N)

  Where:
  - T is the number of test cases
  - N is the size of the vector
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

// Max Queue struct
struct MaxQueue
{
  std::vector<int> sorted;
  size_t it;

  MaxQueue(): it(0) {}

  void push(int a)
  {
    while(it < sorted.size() && sorted.back() < a) sorted.pop_back();
    sorted.push_back(a);
  }

  void pop(int a){ if(sorted[it] == a) it++; }

  int max(){ return sorted[it];  }
};

void solve()
{
  int N, K, tmp;
  struct MaxQueue mq;

  // Read the input
  std::cin >> N >> K;
  std::vector<int> V(N);
  for(int i=0; i<N; i++) std::cin >> V[i];

  // Add the first K values to the max queue
  for(int i=0; i<K; i++) mq.push(V[i]);

  // For each subarray of length K
  for(int i=K; i<N; i++)
  {
    // Print the maximum
    std::cout << mq.max() << " ";
    // Push V[i]
    mq.push(V[i]);
    // And remove the V[i-K]
    mq.pop(V[i-K]);
  }

  // Last subarray
  std::cout << mq.max() << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
