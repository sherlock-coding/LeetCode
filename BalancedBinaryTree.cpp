/*
 * 110 Balanced Binary Tree
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * */

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode * root)
{
    if (!root)
        return 0;

    return max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode * root)
{
    if (!root)
        return true;
 

    return isBalanced(root->left) && isBalanced(root->right) 
        && abs(depth(root->left) - depth(root->right)) < 2;
}

int main()
{
    TreeNode * r = new TreeNode(2);
    cout << depth(r) << endl;
    cout << isBalanced(r) << endl;
}
