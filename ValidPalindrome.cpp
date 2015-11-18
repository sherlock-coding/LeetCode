/*
 * 125 Valid Palindrome
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string s)
{
    if (s.empty())
        return true;

    int i = 0, j = s.size()-1;
    while (i < j) {
        if (!isalnum(s[i])) {
            ++i;
            continue;
        }
        if (!isalnum(s[j])) {
            --j;
            continue;
        }

        if (tolower(s[i++]) != tolower(s[j--]))
            return false;
    }


    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s) << endl;
}
