/*
 * 47 Permutations II
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 回溯
// k表示固定前几个数
void permute_help(vector<int> &a, int k, vector<vector<int>>& ret)
{
    int len = a.size();
    if (k == len-1)
        ret.push_back(a);
    else {
        // candidate
        // 对候选的选择进行筛选
        map<int, bool> m;
        for (int i = k; i < len; ++i) {
            if (m.find(a[i]) != m.end())
                continue;
            m[a[i]] = true;
            swap(a[k], a[i]);
            permute_help(a, k+1, ret);
            swap(a[k], a[i]);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) 
{
    vector<vector<int>> ret;
    permute_help(nums, 0, ret);
    return ret;
}

int main()
{
    vector<int> nums = {3,0,0,2,3};
    vector<vector<int>> ret = permuteUnique(nums);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j)
            cout << ret[i][j] << ",";
        cout << endl;
    }
}
