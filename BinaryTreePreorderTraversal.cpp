/*
 * =====================================================================================
 *
 *       Filename:  BinaryTreePreorderTraversal.cpp
 *
 *    Description:  二叉树前序遍历
 *
 *        Version:  1.0
 *        Created:  2015年05月18日 15时41分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**************递归版本**************/

void help(TreeNode *root, vector<int> &answer)
{
    if (root)
    {
        answer.push_back(root->val);
        help(root->left, answer);
        help(root->right, answer);
    }
}

vector<int> preorderTraversalRecursively(TreeNode *root)
{
    vector<int> answer;
    help(root,answer);
    return answer;
}

/************************************/


/**************迭代版本**************/

vector<int> preorderTraversalIteratively(TreeNode *root)
{
    vector<int> answer;
    stack<TreeNode *> s;
    if (root)
        s.push(root);
    while(!s.empty())
    {
        TreeNode *now = s.top();
        s.pop();
        answer.push_back(now->val);
        if (now->right)
            s.push(now->right);
        if (now->left)
            s.push(now->left);
    }
    return answer;
}

/************************************/

int n = 10;
int a[10] = {1,2,3,4,5,6,7,8,9,10}; 

TreeNode * BuildTree(int i)
{
    if (i>n)
        return NULL;
    TreeNode *root = new TreeNode(a[i-1]);
    root->left = BuildTree(2*i);
    root->right = BuildTree(2*i+1);

    return root;
}

int main()
{
    TreeNode *root = BuildTree(1);
    vector<int> answer = preorderTraversalRecursively(root);
    vector<int> answer1 = preorderTraversalIteratively(root);
    for (auto i : answer)
        cout << i << " ";
    cout << endl;
    for (auto i : answer1)
        cout << i << " ";
    cout << endl;

    return 0;
}
