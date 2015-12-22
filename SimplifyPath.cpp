/*
 * 71 Simplify Path
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"""""""""
 * */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

string simplifyPath(string path)
{
    vector<string> pathsplit;
    int len = path.size();
    int i = 0;
    while (i < len) {
        int l = i;
        while (l < len && path[l] == '/') ++l;
        int r = l;
        while (r < len && path[r] != '/') ++r;
        if (r - l > 0) {
            string tmp = path.substr(l, r-l);
            if (tmp ==".." && pathsplit.size() != 0)
                pathsplit.pop_back();
            if (tmp != "." && tmp != "..")
                pathsplit.push_back(tmp);
        }
        i = r;
    }

    if (pathsplit.size() == 0)
        return "/";
    string ret;
    for (int i = 0; i < pathsplit.size(); ++i)
        ret += "/" + pathsplit[i];

    return ret;
}

string simplifyPathOpt(string path)
{
    istringstream sin(path);
    string str;
    stack<string> st;
    while (getline(sin, str, '/')) {
        if (!str.empty()) {
            if (str == ".." && !st.empty())
                st.pop();
            else if (str != "." && str != "..")
                st.push(str);
        }
    }
    string ret = "";
    while (!st.empty()) {
        ret = "/" + st.top() + ret;           
        st.pop();
    }

    return ret.empty() ? "/" : ret;
}

int main()
{
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("/a/.b/../../c/") << endl;
    cout << simplifyPath("/../") << endl;
    cout << simplifyPath("/") << endl;
    cout << simplifyPath("/home//foo/") << endl;
    cout << simplifyPathOpt("/") << endl;
}
