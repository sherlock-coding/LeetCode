/*
 * 303 Range Sum Query - Immutable
 *
 * iven an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 *
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * */

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums)
    {
        dp.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            dp.push_back(dp[i] + nums[i]);
        }
    }

    int sumRange(int i, int j)
    {
        return dp[j+1] - dp[i];
    }

private:
    vector<int>  dp;
};

int main()
{
    vector<int> nums {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(0,2) << endl;
    cout << numArray.sumRange(2,5) << endl;
    cout << numArray.sumRange(0,5) << endl;
}
