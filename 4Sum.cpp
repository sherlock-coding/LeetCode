/*
 * 18 4Sum
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> ret;
    if (nums.size() < 4)
        return ret;
    sort(nums.begin(), nums.end());
    vector<int> sum(4, 0);
    for (int i = 0; i < nums.size() - 3; ++i) {
        sum[0] = nums[i];
        for (int j = i+1; j < nums.size() - 2; ++j) {
            sum[1] = nums[j];
            int l = j + 1;
            int r = nums.size() - 1;
            while (l < r) {
                while (l < r && nums[i] + nums[j] + nums[l] + nums[r] > target) --r;
                while (l < r && nums[i] + nums[j] + nums[l] + nums[r] < target) ++l;
                if (l < r && nums[i]+nums[j] + nums[l] + nums[r] == target) {
                    sum[2] = nums[l];
                    sum[3] = nums[r];
                    ret.push_back(sum);
                    while (nums[l+1] == nums[l]) ++l;
                    while (nums[r-1] == nums[l]) --r;
                    ++l;
                    --r;
                }
            } 
            while (nums[j+1] == nums[j]) ++j;
        }
        while(nums[i+1] == nums[i]) ++i;
    }

    return ret;
}

int main()
{
    vector<int> nums{1,0,-1,0,-2,2};
    vector<vector<int>> ret = fourSum(nums,0);
    for (int i = 0; i < ret.size(); ++i){
        for (int j = 0; j <ret[i].size(); ++j)
            cout << ret[i][j] << ",";
        cout << endl;
    }
}
