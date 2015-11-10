/*
 * 27 Remove Element
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.'
 * */

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int i = 0, j =0;
    while (j < nums.size()) {
        if (nums[j] != val )
        {
            if (i != j)
                nums[i++] = nums[j];
            else 
                ++i;
        }
        ++j;
    }

    nums.erase(nums.begin()+i, nums.end());

    return i;
}

int main()
{
    vector<int> v = {1,2 ,3,4,5,3,6,5};
    cout << removeElement(v, 3) << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ",";
    cout << endl;
}
