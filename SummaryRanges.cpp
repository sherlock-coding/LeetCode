/*
 * 228 Summary Ranges
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 *
 * """"""]
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> v;
    if (nums.empty())
        return v;

    int start = 0;
    for (int i = 1; i <= nums.size(); ++i) {
        if (nums[i] != nums[i-1] + 1 || i == nums.size()) {
            if (i - 1 == start)
                v.push_back(to_string(nums[start]));
            else
                v.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
            start = i;
        }
    }

    return v;
}

int main()
{
    vector<int> v {0,1,2,4,5,7};
    vector<string> ret = summaryRanges(v);
    for (auto& s :ret )
        cout << s << " ";
    cout << endl;
}
