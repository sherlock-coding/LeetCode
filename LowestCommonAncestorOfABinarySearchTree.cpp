/*
 * 235 Lowest Common Ancestor of a Binary Search Tree
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 * */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
{
    if ((min(p->val, q->val) < root->val &&  max(p->val, q->val) > root->val) || p == root || q == root)
        return root;

    if (min(p->val, q->val) > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return lowestCommonAncestor(root->left, p, q);
}

TreeNode* lowestCommonAncestor1(TreeNode * root, TreeNode * p, TreeNode * q)
{
    while ((p != root && q != root) && (min(p->val, q->val) > root->val ||  max(p->val, q->val) < root->val))
   {
        if (min(p->val, q->val) > root->val)
            root = root->right;
        else
            root = root->left;
    }

    return root;
}

int main()
{

}
