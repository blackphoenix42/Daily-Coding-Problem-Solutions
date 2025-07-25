/*
Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5


You should return 45, as it is (3 + 2) * (4 + 5).

*/

#include <bits/stdc++.h>
using namespace std;
struct Node {
    string val;
    Node* left;
    Node* right;

    Node(string x) : val(x), left(nullptr), right(nullptr) {}
};

int evaluate(Node* root) {
    if (!root) throw invalid_argument("Null node encountered");

    if (!root->left && !root->right) {
        try {
            return stoi(root->val);
        } catch (...) {
            throw invalid_argument("Invalid integer leaf value: " + root->val);
        }
    }

    if (!root->left || !root->right)
        throw invalid_argument("Operator node must have two children: " +
                               root->val);

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    if (root->val == "+") return leftVal + rightVal;
    if (root->val == "-") return leftVal - rightVal;
    if (root->val == "*") return leftVal * rightVal;
    if (root->val == "/") {
        if (rightVal == 0) throw runtime_error("Division by zero");
        return leftVal / rightVal;
    }

    throw invalid_argument("Unknown operator: " + root->val);
}

int main() {
    Node* root = new Node("*");
    root->left = new Node("+");
    root->right = new Node("+");

    root->left->left = new Node("3");
    root->left->right = new Node("2");

    root->right->left = new Node("4");
    root->right->right = new Node("5");

    int result = evaluate(root);
    cout << "Result: " << result << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
