/*
This problem was asked by Etsy.

Given a sorted array, convert it into a height-balanced binary search tree.

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedArrayToBSTHelper(const vector<int> &nums, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = (left + right) / 2;
    TreeNode *node = new TreeNode(nums[mid]);

    node->left = sortedArrayToBSTHelper(nums, left, mid - 1);
    node->right = sortedArrayToBSTHelper(nums, mid + 1, right);

    return node;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}

void preorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = sortedArrayToBST(nums);

    cout << "Preorder traversal of height-balanced BST: ";
    preorder(root);
    cout << endl;

    return 0;
}
