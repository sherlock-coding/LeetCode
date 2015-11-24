/*
 * 219 Contains Duplicate II
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 * */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool containNearbyDuplicate(vector<int>& nums, int k)
{
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.count(nums[i]) != 0) {
            if (i - m[nums[i]] <= k)
                return true;
            else
                m[nums[i]] = i;
        }
        
        m.insert(make_pair(nums[i], i));
    }

    return false;
}

int main()
{
    vector<int> v {1,2,3,4,2};
    cout << containNearbyDuplicate(v, 3) << endl;
}
