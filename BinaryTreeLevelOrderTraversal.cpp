/*
 * 102 Binary Tree Level Order Traversal
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).'
 * */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<pair<TreeNode *, int>> q;
    vector<vector<int>> v;
    if (!root)
        return v;
    q.push(make_pair(root, 0));
    int index = 0;
    vector<int> l;
    while (!q.empty()) {
        TreeNode * tmp = q.front().first;
        int level = q.front().second;
        q.pop();
        if (!tmp)
            continue;
        if (level == index)
            l.push_back(tmp->val);
        else {
            v.push_back(l);
            ++index;
            l.clear();
            l.push_back(tmp->val);
        }
        q.push(make_pair(tmp->left, level+1));
        q.push(make_pair(tmp->right, level+1));

    }
    v.push_back(l);

    return v;
}

int main()
{
    TreeNode r(1);
    vector<vector<int>> v = levelOrder(&r);

    for (int i = 0; i < v.size(); ++i){
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}
