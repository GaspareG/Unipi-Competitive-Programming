/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/largest-even-number/0>

  Solution description:

    Keep the smallest even digit (or odd if there aren't)
    Print the digits of the number in decreasing order,
    print the smallest even (or odd) as last digit).

  Time  complexity: O(T*N)
  Space complexity: O(1)

  Where:
  - T is the number of test cases
  - N is the number of digits

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
  // Read input number
  std::string S;
  std::cin >> S;

  // Count frequencies
  std::vector<int> count(10, 0);
  for(char c : S)
    count[c-'0']++;

  // Take the smallest even (or odd) digit
  int lastDigit = -1;
  for(int i=0; i<10; i+=2)
    lastDigit = (lastDigit == -1 && count[i] > 0) ? i : lastDigit;
  for(int i=1; i<10; i+=2)
    lastDigit = (lastDigit == -1 && count[i] > 0) ? i : lastDigit;

  count[lastDigit]--;

  // Print digits in decreasing order
  for(int i=9; i>=0; i--)
  {
    while(count[i] > 0)
    {
      std::cout << i;
      count[i]--;
    }
  }

  // Print last digit
  std::cout << lastDigit << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for(int i=0; i<T; i++) solve();

  return 0;
}
