/*
 * 46 Permutations
 * Given a collection of numbers, return all possible permutations.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 回溯
void permute_help(vector<int>& a,int k,vector<vector<int>> & ret)
{
    int len = a.size();
    if (k == len - 1)
        ret.push_back(a);
    else {
        for (int i = k; i < len; ++i) {
            swap(a[k], a[i]);
            permute_help(a, k+1, ret);
            swap(a[k], a[i]);
        }
    }
}

// next_permutation
void next_permutations_(vector<int>& nums)
{
    int i = nums.size()-1;
    while (i > 0) {
        if (nums[i] > nums[i-1])
            break;
        --i;
    }

    if (i == 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int j = nums.size()-1; j >= i; --j) {
        if (nums[j] > nums[i-1]) {
            swap(nums[j], nums[i-1]);
            reverse(nums.begin()+i, nums.end());
            return;
        }
    }

}

void permute_help1(vector<int> & nums, vector<vector<int>> & ret)
{
    int n = 1;
    for (int i = 1; i <= nums.size(); ++i)
        n *= i;
    for (int i = 0; i < n; ++i) {
        ret.push_back(nums);
        next_permutations_(nums);
    }
}

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> ret;
    //permute_help(nums, 0, ret);
    permute_help1(nums, ret);
    return ret;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ret = permute(nums);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j)
            cout << ret[i][j] << ",";
        cout << endl;
    }
}
