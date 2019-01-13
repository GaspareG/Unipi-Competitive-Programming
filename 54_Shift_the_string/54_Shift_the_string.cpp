/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://www.codechef.com/problems/TASHIFT>

  Solution description:

    create the string S = A + "$" + B + B
    compute its lps array (as in the kmp algorithm)

    The solution is the first maximum value in lps[N:],
    Let idx be the index of such value,
    the number of shift just evalute is idx-lps[idx]-N

  Time  complexity: O(N)
  Space complexity: O(N)

  Where:
  - N is the size of input strings

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

  int N;

  std::string A, B;
  std::cin >> N;
  std::cin >> A >> B;
  std::string S = A + "$" + B + B;
  std::vector<int> lps(S.size(), 0);

  int len = 0;
  size_t i = 1;

  while (i<S.size())
  {
    if (S[i] == S[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
      {
        len = lps[len-1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }

  int sol = N;
  for(size_t k=N; k<S.size(); k++)
  {
    if(lps[k] > lps[sol])
      sol = k;
  }

  sol = sol-lps[sol] - N;

  std::cout << sol << std::endl;

  return 0;
}
