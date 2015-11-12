/*
 * 58 Length of Last Word
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * ''
 * */

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) 
{
    auto it = s.rbegin();
    int cnt  = 0;
    while (it != s.rend()) {
        if (*it != ' ') {
            ++cnt;
        }
        else {
            if (cnt)
                return cnt;
        }

        ++it;
    }

    return cnt;
}

int main()
{
    string s = "Hello world";
    cout << lengthOfLastWord(s) << endl;
}
