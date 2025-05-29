/*
This problem was asked by Oracle.

Given a binary search tree, find the floor and ceiling of a given integer. The floor is the highest element in the tree less than or equal to an integer, while the ceiling is the lowest element in the tree greater than or equal to an integer.

If either value does not exist, return None.
*/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int floor = -1, ceil = -1;

    void findFloor(TreeNode *node, int x)
    {
        if (!node)
            return;

        if (node->val == x)
        {
            floor = x;
            return;
        }

        if (node->val > x)
        {
            findFloor(node->left, x);
        }
        else
        {
            floor = node->val;
            findFloor(node->right, x);
        }
    }

    void findCeil(TreeNode *node, int x)
    {
        if (!node)
            return;

        if (node->val == x)
        {
            ceil = x;
            return;
        }

        if (node->val < x)
        {
            findCeil(node->right, x);
        }
        else
        {
            ceil = node->val;
            findCeil(node->left, x);
        }
    }

    pair<int, int> floorCeilBST(TreeNode *root, int x)
    {
        floor = ceil = -1;
        findFloor(root, x);
        findCeil(root, x);
        return {floor, ceil};
    }
};

int main()
{
    /*
            8
           / \
          4   12
         / \    \
        2   6    14
    */
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);

    Solution sol;

    // Test cases
    for (int x : {1, 5, 8, 10, 15})
    {
        auto [floor, ceil] = sol.floorCeilBST(root, x);
        cout << "x = " << x << " → Floor: " << floor << ", Ceil: " << ceil << endl;
    }

    return 0;
}
