/*
 * 290 Word Pattern
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 *
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.""""""""""""""""
 * */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

bool wordPattern(string pattern, string str)
{
    vector<string> vs;
    int start = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            vs.push_back(str.substr(start,i - start));
            start = i+1;
        }
    }
    vs.push_back(str.substr(start, str.size() - start));

    if (vs.size() != pattern.size())
        return false;

    map<char, string> m;
    set<string> s;
    for (int i = 0; i < pattern.size(); ++i) {
        if (m.count(pattern[i]) == 0) {
            if (s.count(vs[i]) != 0)
                return false;
            m.insert(make_pair(pattern[i], vs[i]));
            s.insert(vs[i]);
        }
        else {
            if (m[pattern[i]] != vs[i])
                return false;
        }
    }

    return true;
}


int main()
{
    string pattern = "abba";
    string str = "dog cat cat dog";
    cout << wordPattern(pattern, str) << endl;
}
