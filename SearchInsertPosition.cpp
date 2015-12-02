/*
 * 35 Search Insert Position
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 * */

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    if (nums.size() == 0 || target < nums[0]) return 0;
    if (target > nums[nums.size() - 1]) return nums.size();
    auto itl = nums.begin();
    auto itr = nums.end();
    while (itl != itr) {
        auto mid = itl + (itr - itl) / 2;
        if (*mid == target)
            return mid - nums.begin();
        else if (*mid > target)
            itr = mid;
        else 
            itl = mid + 1;
    }

    return itl - nums.begin();
}

int main()
{
    vector<int> v ={1,3,5,6};
    cout << searchInsert(v, 5)<< endl;
    cout << searchInsert(v, 2) << endl;
    cout << searchInsert(v, 7) << endl;
    cout << searchInsert(v, 0) << endl;
}
