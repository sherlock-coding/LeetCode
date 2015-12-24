/*
 * 33 Search in Rotated Sorted Array
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 * */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target) 
{
    int sz = nums.size();
    int l = 0, r = sz - 1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target) {
            if (target >= nums[l] || nums[mid] < nums[l])
                r = mid - 1;
            else
                l = mid+1;
        } else {
            if (target < nums[l] || nums[mid] >= nums[l])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    return -1;
            
}

int main()
{
    vector<int> v{4,5,6,7,0,1,2};
    cout << search(v, 5) << endl;
    cout << search(v, 1) << endl;
    cout << search(v, 8) << endl;
}
