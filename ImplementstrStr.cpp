/*
 * 28 Implement strStr()
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * */

#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle)
{
    int hlen = haystack.size();
    int nlen = needle.size();
    if (hlen < nlen)
        return -1;
    for (int i = 0; i <= hlen-nlen; ++i)
    {
        int j = 0;
        for (; j < nlen; ++j)
            if (haystack[i+j] != needle[j])
                break;
        if (j == nlen)
            return i;
    }

    return -1;
}

int main()
{
    string a= "123456";
    string b= "345";
    cout << strStr(a, b) << endl;
}
