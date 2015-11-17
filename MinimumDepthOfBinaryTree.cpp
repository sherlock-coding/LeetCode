/*
 * 111 Minimum Depth of Binary Tree
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * */

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

int minDepth(TreeNode *root)
{
    if (!root)
        return 0;

    int ld = minDepth(root->left);
    int rd = minDepth(root->right);
    return (ld && rd) ? min(ld,rd)+1 : ld+rd+1;
}

int main()
{

}
