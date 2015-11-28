/*
 * 15 3Sum
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ret;
    if (nums.size() < 3)
        return ret;
    sort(nums.begin(), nums.end());
    vector<int> t(3, 0);

    for (int i = 0; i < nums.size() - 2; ++i) {
        if (nums[i] > 0)
            break;
        int l = i + 1;
        int r = nums.size() - 1;
        t[0] = nums[i];
        while (l < r) {
            while (l < r && nums[l] + nums[r] > -nums[i]) --r;
            while (l < r && nums[l] + nums[r] < -nums[i]) ++l;
            if (l < r && nums[l] + nums[r] == -nums[i]) {               
                t[1] = nums[l];
                t[2] = nums[r];
                ret.push_back(t);
                while (nums[l+1] == nums[l]) ++l;
                while (nums[r-1] == nums[r]) --r;
                ++l;
                --r;
            }
        }
        while (nums[i] == nums[i+1])
            ++i;
    }

    return ret;
}

int main()
{
    vector<int> v{-1,0,1,2,-1,-4};
    vector<vector<int>> ret = threeSum(v);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0;j < ret[i].size(); ++j)
            cout << ret[i][j] << " ";
        cout << endl;
    }
}
