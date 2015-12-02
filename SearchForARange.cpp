/*
 * 34 Search for a Range
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].'
 * */

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    if (nums.size() == 0 || nums[0] > target || nums[nums.size()-1] < target)
        return vector<int>{-1,-1};

    vector<int> ret;
    auto itl = nums.begin();
    auto itr = nums.end();
    while (itl != itr) {
        auto mid = itl + (itr-itl)/2;
        if (*mid == target) {
            auto it = mid;
            while (it != itl) {
                if (*it != target) {
                    break;
                }
                --it;
            }
            if (*it != target) ++it;
            ret.push_back(it - nums.begin());

            it = mid;
            while (it != itr) {
                if (*it != target)
                    break;
                ++it;
            }
            ret.push_back(it - nums.begin() - 1);
            return ret;
        } else if (*mid < target)
            itl = mid+1;
        else
            itr = mid;
    }

    return vector<int>{-1,-1};
}

int main()
{
    vector<int> v = {5, 7, 7, 8, 8, 10};
    for (auto &i : searchRange(v, 8))
        cout << i << " ";
    cout << endl;
}
