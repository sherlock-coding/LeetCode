/*
 * 26 Remove Duplicates from Sorted Array
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * */

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int sz = nums.size();
    int i = 0, j = 0;

    while (i < sz) {
        while (j < sz) {
            if (nums[j] != nums[i])
                break;
            ++j;
        }
        if (j == sz)
            return i+1;
        nums[++i] = nums[j++];
    }
}

int main()
{
    vector<int> nums = {1,2,2,4,5,6,6,7};
    cout << removeDuplicates(nums) << endl;
}
