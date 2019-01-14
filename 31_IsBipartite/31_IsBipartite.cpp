/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/bipartite-graph/1>

  Solution description:

    Just a dfs over the graph and coloring each node.

  Time  complexity: O(T*N²)
  Space complexity: O(N²)

  Where:
  - T is the number of test cases
  - N is the number of vertex in graph
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

{
// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
  cin>>t;
  int g[MAX][MAX];
  while(t--)
  {
    memset(g,0,sizeof (g));
    int n;
    cin>>n;
  
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin>>g[i][j];
      }
    }
    
    cout<<isBipartite(g,n)<<endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
#include <vector>

bool dfs(vector<int>& seen, int G[][MAX], int idx, int V)
{
    for(int i=0; i<V; i++)
    {
        if(i == idx) continue;
        if(G[idx][i] == 0) continue;
        if(seen[i] == 0)
        {
            seen[i] = seen[idx] == 1 ? 2 : 1;
            if(!dfs(seen, G, i, V))
                return false;
        }
        else if(seen[idx] == seen[i])
            return false;
    }

    return true;
}

bool isBipartite(int G[][MAX],int V)
{
    // no self-loop
    for(int i=0; i<V; i++)
        if(G[i][i] == 1) return false;

    vector<int> seen(V, 0); // 0 = unseen, 1 = white, 2 = black
    bool sol = true;

    for(int i=0; i<V && sol; i++)
    {
        if(seen[i] != 0) continue;
        seen[i] = 1;
        sol &= dfs(seen, G, i, V);
    }
    return sol;
}
