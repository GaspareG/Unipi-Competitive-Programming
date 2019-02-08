/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/maximum-path-sum/1>

  Solution description:

    Just compute the diameter of the tree.

  Time  complexity: O(T*N)
  Space complexity: O(N)

  Where:
  - T is the number of test cases
  - N is the size of the tree
*/

#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node *left, *right;
};
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int maxPathSum(struct Node *root);
void insert(Node *root, int a1,int a2, char lr){
  if(root==NULL)
    return ;
  if(root->data==a1){
    switch(lr){
      case 'L':root->left=newNode(a2);
          break;
      case 'R':root->right=newNode(a2);
          break;
    }
  }
  insert(root->left,a1,a2,lr);
  insert(root->right,a1,a2,lr);
}
void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right)
;}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    Node *root=NULL;
    while(n--){
      int a1,a2;
      char lr;
      cin>>a1>>a2>>lr;
      if(root==NULL){
        root=newNode(a1);
        switch(lr){
          case 'L':root->left=newNode(a2);
              break;
          case 'R':root->right=newNode(a2);
              break;
        }
      }
      else
        insert(root,a1,a2,lr);
    }
    //inorder(root);
    //cout<<endl;
    cout<<maxPathSum(root)<<endl;
  }
}

/*****************************************************************************/
/* Code to upload                                                            */

int dfs(struct Node *root, int &sol)
{
  if(root == NULL) return 0;
  int left = std::max(0, dfs(root->left, sol));
  int right = std::max(0, dfs(root->right, sol));
  sol = std::max(sol, left+right+(root->data));
  return std::max(left+(root->data), right+(root->data));
}

int maxPathSum(struct Node *root)
{
  int sol = 0;
  dfs(root, sol);
  return sol;
}
/*****************************************************************************/
