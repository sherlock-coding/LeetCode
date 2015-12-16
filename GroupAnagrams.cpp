/*
 * 29 Group Anagrams
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *     ["nat","tan"],
 *       ["bat"]
 *       ]
 *       Note:
 *       For the return value, each inner list's elements must follow the lexicographic order.
 *       All inputs will be in lower-case.'""]""""]""""""]]""""""""""""]
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> ret;
    unordered_map<string, int> m;
    for (auto& s : strs) {
        string tmp(s);
        sort(tmp.begin(), tmp.end());
        auto it = m.find(tmp);
        if (it != m.end()) {
            ret[it->second].push_back(s);
            sort(ret[it->second].begin(), ret[it->second].end());
        }else {
            m[tmp] = ret.size();
            ret.push_back(vector<string>{s});
        }
    }

    return ret;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ret = groupAnagrams(strs);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j)
            cout << ret[i][j] << ",";
        cout << endl;
    }
}
