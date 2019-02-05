/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <url>

  Solution description:
  
    We need to find, for each position 0 <= i < N how many
    segments lies in it. To do this we can create an array count[N]
    initially filled with 0, for each segment [l, r] we add +1 to count[l]
    and -1 to count[r+1], finally after a prefix-sum pass we obtain 
    the desiderd array.
  
    As second step we build an array freq[N] where for eacy frequency k
    we want to know all the index of position with k segments in it.
    To do this it's enough to process the count array and insert the indices
    in the correct position
    
    Also note that for each i the array freq[i] is increasingly sorted
    (As in the previous phase we built it from 0 to N-1).
    
    Finally the answer each of the query [i, j, k] is 1 if exists and index p
    between i and j in freq[k], 0 otherwise.
    
    This could be simply done with a lower bound search of i over freq[k] 
    and by checking if the corresponding elements in less or equal than r.
      
    The first and the second preprocessing step cost O(N)
    and for each of the M queries we need an O(log(N)) binary search thus
    the total time complexity is O(N+M*log(N)).
    
    

  Time  complexity: O(N+M*log(N))
  Space complexity: O(N)

  Where:
    - N is the number of segments
    - M is the number of queries
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
  int N, M;
  std::cin >> N >> M;
  int l, r, k;
  std::vector<int> count(N+1, 0);
  std::vector<std::vector<int>> freq(N+1);

  // Read segments
  for(int i=0; i<N; i++)
  {
    std::cin >> l >> r;
    count[l]++;
    count[r+1]--;
  }

  // Get frequencies
  for(int i=0; i<N; i++) count[i+1] += count[i];
  for(int i=0; i<N; i++) freq[count[i]].push_back(i);

  // Read queries
  for(int i=0; i<M; i++)
  {
    std::cin >> l >> r >> k;
    auto it = std::lower_bound(freq[k].begin(), freq[k].end(), l);
    int sol = (it != freq[k].end()) && ((*it) <= r);
    std::cout << sol << std::endl;
  }

  return 0;
}
