/*
 * 205 Isomorphic String
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 * */

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>

using namespace std;

bool isIsomorphic(string s, string t)
{
    int sz = s.size();
    if (sz != t.size())
        return false;

    map<char, char> m;
    set<char> mt;
    for (int i = 0; i < sz; ++i) {
        if (m.count(s[i]) == 0) {
            if (mt.count(t[i]) != 0)
                return false;
            m.insert(make_pair(s[i], t[i]));
            mt.insert(t[i]);
        }
        else {
            if (t[i] != m[s[i]])
                return false;
        }
    }

    return true;
}

int main()
{
    string s = "aa";
    string t = "ab";
    cout << isIsomorphic(s,t) << endl;
}
