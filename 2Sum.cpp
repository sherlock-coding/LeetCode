/*
 * 1 Two Sum
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 * 
 * */

#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> ret;
    map<int, int> m;

    for (int i = 0; i < nums.size(); ++i) {
        if (m.count(target - nums[i]) != 0) {
            ret.push_back(m[target-nums[i]]);
            ret.push_back(i+1);
        }

        m.insert(make_pair(nums[i], i+1));
    }

    return ret;
}

int main()
{
    vector<int> nums{2,7,11,15};
    vector<int> ret = twoSum(nums, 9);
    for (auto i : ret)
        cout << i << " ";
    cout << endl;
}
