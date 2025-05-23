/*
This problem was asked by Google.

Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

    a
   / \
  b   c
 / \ / \
d  e f  g
*/

#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// Tree builder class
class Solution
{
    unordered_map<char, int> inorderMap;
    int preorderIndex = 0;

public:
    TreeNode *buildTree(vector<char> &preorder, vector<char> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
            inorderMap[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *build(const vector<char> &preorder, int inStart, int inEnd)
    {
        if (inStart > inEnd)
            return nullptr;

        char rootVal = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootVal);
        int inIndex = inorderMap[rootVal];

        root->left = build(preorder, inStart, inIndex - 1);
        root->right = build(preorder, inIndex + 1, inEnd);
        return root;
    }
};

void printLevelOrder(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node)
            {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                cout << "null ";
            }
        }
        cout << endl;
    }
}

// Main
int main()
{
    vector<char> preorder = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
    vector<char> inorder = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    cout << "Level Order Traversal of Reconstructed Tree:\n";
    printLevelOrder(root);

    return 0;
}
