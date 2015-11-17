/*
 * 107 Binary Tree Level Order Traversal II
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).'
 * */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> v;
    if (!root)
        return v;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    int curlevel = 0;
    vector<int> leveldata;
    
    while (!q.empty()) {
        TreeNode *tmp = q.front().first;
        int level = q.front().second;
        q.pop();
        if (level != curlevel) {
            v.push_back(leveldata);
            leveldata.clear();
            curlevel = level;
        }
        leveldata.push_back(tmp->val);
        if (tmp->left)
            q.push(make_pair(tmp->left, level + 1));
        if (tmp->right)
            q.push(make_pair(tmp->right, level + 1));
    }
    if (!leveldata.empty())
        v.push_back(leveldata);

    reverse(v.begin(), v.end());

    return v;
}

int main()
{
    TreeNode * r = new TreeNode(1);
    TreeNode * l = new TreeNode(2);
    TreeNode * r1 = new TreeNode(3);
    r->left = l;
    r->right = r1;
    vector<vector<int>> v = levelOrderBottom(r);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}
