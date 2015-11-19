/*
 * 169 Majority Element
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int> & nums)
{
    unordered_map<int,size_t> m;
    for (auto i : nums) {
        if (m.count(i) == 0)
            m.insert(make_pair(i, 1));
        else
            ++m[i];
    }

    using m_type = unordered_map<int,size_t>::value_type;
    auto it = max_element(m.begin(), m.end(), [](m_type lhs, m_type rhs) { return lhs.second < rhs.second; });

    return it->first;
}

int main()
{

}
