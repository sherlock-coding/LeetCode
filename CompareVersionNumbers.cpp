/*
 * 165 Compare Version Numbers
 * ompare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.""""
 * */

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

vector<int> split(string str)
{
    auto it = str.find('.');
    vector<int> ret;
    decltype(it)  pre = 0;
    while (it != string::npos) {
        ret.push_back(stoi(str.substr(pre, it)));
        pre = it+1;
        it = str.find('.', pre);
    }
    ret.push_back(stoi(str.substr(pre)));

    return ret;
}

int compareVersion(string version1, string version2)
{
    vector<int> i1 = split(version1);
    vector<int> i2 = split(version2);

    for (int i = 0; i < min(i1.size(),i2.size()); ++i) {
        if (i1[i] > i2[i])
            return 1;
        else if (i1[i] < i2[i])
            return -1;
        else
            continue;
    }

    if (i1.size() > min(i1.size(), i2.size()))
        for(int i = min(i1.size(), i2.size()); i < i1.size(); ++i)
            if (i1[i] > 0)
                return 1;
    if (i2.size() > min(i1.size(), i2.size()))
        for (int i = min(i1.size(), i2.size()); i < i2.size(); ++i)
            if (i2[i] > 0)
                return -1;

    return 0;
}

int main()
{
    string a = "1.1";
    string b = "1.10";
    cout << compareVersion(a,b) << endl;
}
