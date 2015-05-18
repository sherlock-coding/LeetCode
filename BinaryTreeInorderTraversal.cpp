/*
 * =====================================================================================
 *
 *       Filename:  BinaryTreeInorderTraversal.cpp
 *
 *    Description:  二叉树前序遍历
 *
 *        Version:  1.0
 *        Created:  2015年05月18日 16时41分02秒
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
#include <utility> // std::pair

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
        help(root->left, answer);
        answer.push_back(root->val);
        help(root->right, answer);
    }
}

vector<int> inorderTraversalRecursively(TreeNode *root)
{
    vector<int> answer;
    help(root,answer);
    return answer;
}

/************************************/


/**************迭代版本**************/

vector<int> inorderTraversalIteratively(TreeNode *root)
{
    vector<int> answer;
    // pair.sencond, 0表示左子树未访问， 1表示左子树已访问
    stack<pair<TreeNode *, int>> s;
    if (root)
        s.push(make_pair(root, 0));
    while(!s.empty())
    {
        TreeNode *now = s.top().first;
        switch(s.top().second)
        {
            case 0:
                ++s.top().second;
                if (now->left)
                    s.push(make_pair(now->left, 0));
                break;
            case 1:
                s.pop();
                answer.push_back(now->val);
                if (now->right)
                    s.push(make_pair(now->right, 0));
                break;
        }
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
    vector<int> answer = inorderTraversalRecursively(root);
    vector<int> answer1 = inorderTraversalIteratively(root);
    for (auto i : answer)
        cout << i << " ";
    cout << endl;
    for (auto i : answer1)
        cout << i << " ";
    cout << endl;

    return 0;
}
