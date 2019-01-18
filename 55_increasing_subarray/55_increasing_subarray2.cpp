#include <iostream>
#include <utility>
#include <array>
#include <vector>

int main()
{
  std::ios_base::sync_with_stdio(false);

  int N, sol = 0;
  std::cin >> N;
  std::vector<int> V(N);
  std::vector<std::array<int, 2>> pos;

  for(int i=0; i<N; i++) std::cin >> V[i];
  for(int i=0, j=0; i<N; i++, j=i)
  {
    while(j+1 < N && V[j] < V[j+1]) j++;
    pos.push_back({i, j});
    sol = std::max(sol, (j-i+1));
  }

  sol = std::min(sol+1, N);

  for(int i=0; i<pos.size()-1; i++)
    if(pos[i][0] != pos[i][1] && V[pos[i+1][0]] - V[pos[i][1]-1] > 1)
        sol = std::max(sol, pos[i+1][1]-pos[i][0]+1);

  for(int i=0; i<pos.size()-1; i++)
    if(pos[i+1][0] != pos[i+1][1] && V[pos[i+1][0]+1] - V[pos[i][1]] > 1)
        sol = std::max(sol, pos[i+1][1]-pos[i][0]+1);

  for(int i=0; i<pos.size()-2; i++)
    if(pos[i+1][0] == pos[i+1][1] && V[pos[i+2][0]] - V[pos[i][1]] > 1)
      sol = std::max(sol, pos[i+2][1]-pos[i][0]+1);

  std::cout << sol << std::endl;

  return 0;
}
