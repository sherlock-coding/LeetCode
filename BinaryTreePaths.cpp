/*
 * 257 Binary Tree Paths
 * Given a binary tree, return all root-to-leaf paths.
 * */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void DFS(TreeNode *root, vector<string> & ret, string path)
{
    if (root->left == NULL && root->right == NULL) {
        if (path.empty())
            ret.push_back(to_string(root->val));
        else
            ret.push_back(path + "->" +  to_string(root->val));
        return;
    }

    if (path.empty())
        path = to_string(root->val);
    else
        path += "->"+ to_string(root->val);
    if (root->left)
        DFS(root->left,ret,path);
    if (root->right)
        DFS(root->right, ret,path);        
}

void DFSOpt(TreeNode *root, vector<string> & ret)
{
    stack<pair<TreeNode *, int> > st;
    st.push(make_pair(root, 0)); // 0表示子树都未访问，1表示左子树已访问，2表示右子树已访问;
    vector<int> path;

    while (!st.empty()) {
        TreeNode * cur = st.top().first;
        switch (st.top().second){
        case 0:
            path.push_back(cur->val);
            ++(st.top().second);
            if (cur->left)
                st.push(make_pair(cur->left, 0));
            break;
        case 1:
            ++(st.top().second);
            if (cur->right)
                st.push(make_pair(cur->right, 0));
            break;
        case 2:
            if (cur->left == NULL && cur->right == NULL) {
                string tmp = to_string(path[0]);
                for (int i = 1; i < path.size(); ++i)
                    tmp += "->" + to_string(path[i]);
                ret.push_back(tmp);
            }

            path.pop_back();
            st.pop();
            break;
        default:
            return;
            break;
        }
    }

}

vector<string> binaryTreePaths(TreeNode * root)
{
    vector<string> ret;
    /*
    string tmp;
    if (root)
        DFS(root, ret,tmp);
    */
    if (root)
        DFSOpt(root, ret);

    return ret;
}
int main()
{

}
