/*
 * 198 House Robber
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) 
{
    if (nums.empty())
        return 0;
    int sz = nums.size();
    int dp[sz+1];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= sz; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
    }

    return dp[sz];
}

int main()
{
}


