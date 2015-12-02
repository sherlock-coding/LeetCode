/*
 * 39 Combination Sum
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& a,int sum, int target, int k, int len,vector<int>& nums ,vector<vector<int>>& ret)
{

    if (sum == target) {
        ret.push_back(a);
        return;
    }
    else {
        if (k == len || nums[k] > target)
            return;
        vector<int> c;
        for (int i = 0; i * nums[k]+ sum <= target; ++i) 
            c.push_back(i);

        for (int i = 0; i < c.size(); ++i) {
            if (c[i] == 0) {
                backtrack(a, sum, target, k+1, len, nums, ret);
            } else {
                sum += c[i]*nums[k];
                vector<int> tmp(i, nums[k]);
                a.insert(a.end(), tmp.begin(), tmp.end());
                backtrack(a, sum, target, k+1, len, nums, ret);
                a.erase(a.begin() + a.size() - tmp.size(), a.end());
                sum -= c[i]*nums[k];
            }
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ret;
    vector<int> a;
    backtrack(a, 0, target, 0, candidates.size(), candidates, ret);
    return ret;
}

int main()
{
    vector<int> v {2,3,6,7};
    vector<vector<int>> ret = combinationSum(v, 7);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j <ret[i].size(); ++j)
            cout << ret[i][j] << ",";
        cout << endl;
    }
}
