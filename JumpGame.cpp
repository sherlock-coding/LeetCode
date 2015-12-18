/*
 * 55 Jump Game
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 * */

#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums)
{
    if (nums.size() <= 1)
        return true;

    int last = nums.size() - 1;
    for (int i = last - 1; i >= 0; --i) {
        if (i + nums[i] >= last)
            last = i;
    }
    if (last == 0)
        return true;
    return false;
}

int main()
{
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums) << endl;
}
