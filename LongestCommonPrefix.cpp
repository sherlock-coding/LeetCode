/*
 * 14 Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    if (strs.size() == 0)
        return string();
    size_t sz = strs.size();
    size_t minstrsz = strs[0].size();

    for (int i = 1; i < sz; ++i)
        if (strs[i].size() < minstrsz)
            minstrsz = strs[i].size();

    for (int i = 0; i < minstrsz; ++i)
        for (int j = 1; j < sz; ++j)
            if (strs[j][i] != strs[j-1][i])
                return strs[0].substr(0, i);   

    return strs[0].substr(0, minstrsz);
}

int main()
{
    vector<string> strs = {"abd","abcd", "abed"};
    cout << longestCommonPrefix(strs);

}


 
