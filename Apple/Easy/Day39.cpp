/*
This question was asked by Apple.

Given a binary tree, find a minimum path sum from root to a leaf.

For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.

  10
 /  \
5    5
 \     \
   2    1
       /
     -1

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

int minPathSum(Node *root)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }

    if (root->left == nullptr and root->right == nullptr)
    {
        return root->val;
    }

    int left = minPathSum(root->left);
    int right = minPathSum(root->right);

    int ans = root->val + min(left, right);

    return ans;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(5);
    root->left->right = new Node(2);
    root->right->right = new Node(1);
    root->right->right->left = new Node(-1);

    cout << " Minimum Path Sum : " << minPathSum(root) << endl;

    return 0;
}