/*
This problem was asked by Amazon.

A tree is symmetric if its data and shape remain unchanged when it is reflected about the root node. The following tree is an example:

        4
      / | \
    3   5   3
  /           \
9              9
Given a k-ary tree, determine whether it is symmetric.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isMirror(Node *t1, Node *t2)
    {
        if (!t1 && !t2)
            return true;
        if (!t1 || !t2 || t1->val != t2->val)
            return false;

        return isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }

    bool isSymmetric(Node *root)
    {
        if (!root)
            return true;
        return isMirror(root->left, root->right);
    }
};

int main()
{
    Node *root = new Node(4);
    root->left = new Node(3);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->right->right = new Node(9);

    Solution sol;
    cout << (sol.isSymmetric(root) ? "Symmetric" : "Not Symmetric") << endl;

    return 0;
}
