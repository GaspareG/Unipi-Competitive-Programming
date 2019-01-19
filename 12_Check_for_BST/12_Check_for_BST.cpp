/*
  Author: Gaspare Ferraro <ferraro@gaspa.re>
  Problem: <https://practice.geeksforgeeks.org/problems/check-for-bst/1>

  Solution description:

    Just a DFS with left/right control

  Time  complexity: O(T*N)
  Space complexity: O(N)

  Where:
  - T is the number of test cases
  - N is the size of the tree
*/

#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBST(root) << endl;
  }
  return 0;
}

/****************************************************************************+*/
/* CODE TO UPLOAD                                                             */
bool isBST(Node*root, int lv, int rv)
{
  if(root == NULL) return true;

  int data = root->data;

  if(lv > data || rv < data) return false;

  if(root->left != NULL)
  {
    int left = (root->left)->data;
    if(left > data) return false;
    if(!isBST(root->left, lv, data-1)) return false;
  }

  if(root->right != NULL)
  {
    int right = (root->right)->data;
    if(right < data) return false;
    if(!isBST(root->right, data+1, rv)) return false;
  }

  return true;
}

bool isBST(Node* root){ return  isBST(root, 1, 1000); }
/****************************************************************************+*/
