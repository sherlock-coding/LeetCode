/*
 * 226 Invert Binary Tree
 *
 * */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * invertRecursive(TreeNode * root) 
{
    if (!root)
        return NULL;

    invertRecursive(root->left);
    invertRecursive(root->right);
    swap(root->left, root->right);
    return root;
}

TreeNode * invertTree(TreeNode * root) 
{
    if (!root)
        return NULL;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
        swap(cur->right, cur->left);
    }

    return root;
}

int main()
{

}
