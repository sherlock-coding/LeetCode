/*
 * 101 Symmetric Tree
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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

// 判断两颗子树是否对称
bool isMirror(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;

    return p->val == q->val && isMirror(p->left, q->right) && isMirror(p->right, q->left);
}

// 递归
bool isSymmetricRecursive(TreeNode * root)
{
    if (!root)
        return true;

   return isMirror(root->left, root->right); 
}

// 迭代
bool isSymmetricIterative(TreeNode * root)
{
    if (!root )
        return true;

    queue<TreeNode *> l,r;
    l.push(root->left);
    r.push(root->right);
    while (!l.empty() && !r.empty()) {
        TreeNode *ln = l.front();
        TreeNode *rn = r.front();
        l.pop();
        r.pop();
        if (!ln && !rn)
            continue;
        else if (!ln || !rn || ln->val != rn->val)
            return false;

        l.push(ln->left);
        l.push(ln->right);
        r.push(rn->right);
        r.push(rn->left);
    }

    return true;

}

int main()
{

}
