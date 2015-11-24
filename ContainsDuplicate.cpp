/*
 * 217 Contains Duplicate
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 * */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containDuplicate(vector<int>& nums)
{
    set<int> s;
    for (const auto &i : nums) {
        if (s.count(i) != 0)
            return true;
        s.insert(i);
    }

    return false;
}

int main()
{
    vector<int> v{1,2,3,4,5};
    cout << containDuplicate(v) << endl;
}
