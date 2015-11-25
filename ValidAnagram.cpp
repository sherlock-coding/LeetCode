/*
 * 242 Valid Anagram
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.""""""""
 * */

#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    int tb[26];
    fill(tb, tb+26, 0);

    for (const auto & c : s)
        ++tb[c - 'a'];

    for (const auto & c : t) 
        --tb[c - 'a'];

    for (int i = 0; i < 26; ++i)
        if (tb[i] != 0)
            return false;

    return true;
}

int main()
{

}
