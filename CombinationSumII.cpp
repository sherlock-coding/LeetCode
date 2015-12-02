/*
 * 40 Combination Sum II
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& a, int target, int k, int len, vector<int>& nums, vector<vector<int>>& ret)
{
    if (target == 0) 
        ret.push_back(a);
    else {
        if (k == len)
            return;

        int c;
        for (c = k; c < len - 1; ++c) {
            if (nums[c+1] != nums[c])
                break;
        }
        c = c - k + 1;
        for (int i = 0; i <= c; ++i) {
            if (i == 0) 
                backtrack(a, target, k+c, len, nums, ret);
            else {
                if (i*nums[k] <= target) {
                    vector<int> tmp (i, nums[k]);
                    a.insert(a.end(), tmp.begin(), tmp.end());
                    backtrack(a, target - i * nums[k], k + c, len, nums, ret);
                    a.erase(a.begin()+ a.size() - i, a.end());
                }else
                    break;
            }
        }
    }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>> ret;
    vector<int> a;
    sort(candidates.begin(), candidates.end());
    backtrack(a, target, 0, candidates.size(), candidates, ret);
    return ret;
}


int main()
{
    vector<int> v {10,1,2,7,6,1,5};
    vector<vector<int>> ret = combinationSum2(v, 8);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j)
            cout << ret[i][j] << ",";
        cout << endl;
    }

}
