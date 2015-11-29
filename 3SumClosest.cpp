/*
 * 16 3Sum Closest
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int threeSumClosest(vector<int> & nums, int target)
{
    sort(nums.begin(), nums.end());
    int ret = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; ++i) {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r) {
            while (l < r && nums[l] + nums[r] + nums[i] < target) ++l;
            if (l - 1 != i && abs(nums[i] + nums[l-1] + nums[r] - target) < abs(ret - target))
                ret = nums[i] + nums[l-1] + nums[r];
            while (l < r && nums[l] +nums[r] + nums[i] > target) --r;
            if (r+1 != nums.size() && abs(nums[i] + nums[l] + nums[r+1] -target) < abs(ret - target))
                ret = nums[i] + nums[l] + nums[r+1];

            if (l < r && nums[i] + nums[l] + nums[r] ==  target) {
                return target;
            }
            
        }
    }

    return ret;
}

int main()
{
    vector<int> nums{1,2,4,8,16,32,64,128};
    cout << threeSumClosest(nums, 82)<< endl;
}
