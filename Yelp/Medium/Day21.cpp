/*
This problem was asked by Yelp.

The horizontal distance of a binary tree node describes how far left or right the node will be when the tree is printed out.

More rigorously, we can define it as follows:

The horizontal distance of the root is 0.
The horizontal distance of a left child is hd(parent) - 1.
The horizontal distance of a right child is hd(parent) + 1.
For example, for the following tree, hd(1) = -2, and hd(6) = 0.

             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8
The bottom view of a tree, then, consists of the lowest node at each horizontal distance. If there are two nodes at the same depth and horizontal distance, either is acceptable.

For this tree, for example, the bottom view could be [0, 1, 3, 6, 8, 9].

Given the root to a binary tree, return its bottom view.

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(map<int, pair<int, int>> &umap, TreeNode *node, int HD, int depth)
{
    if (node == nullptr)
    {
        return;
    }

    if (umap.find(HD) == umap.end() || depth >= umap[HD].second)
    {
        umap[HD] = {node->val, depth};
    }

    dfs(umap, node->left, HD - 1, depth - 1);
    dfs(umap, node->right, HD + 1, depth + 1);
}

vector<int> bottomView(TreeNode *root)
{
    vector<int> res;
    map<int, pair<int, int>> umap;
    dfs(umap, root, 0, 0);

    for (auto it : umap)
    {
        res.push_back(it.second.first);
    }
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(0);
    root->right->right->left = new TreeNode(8);

    vector<int> result = bottomView(root);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}
