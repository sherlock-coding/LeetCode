/*
 * 20 Valid Parentheses
 *  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 *  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.")"")"""""''']''''}'''')'
 * */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> st;
    int sz = s.size();

    for (int i = 0; i < sz; ++i)
    {
        switch(s[i]) {
            case '(':
                st.push(s[i]);
                break;
            case ')':
                if(st.empty() || st.top() != '(')
                    return false;
                st.pop();
                break;
            case '[':
                st.push(s[i]);
                break;
            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
                break;
            case '{':
                st.push(s[i]);
                break;
            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
                break;
            default:
                break;
        }
    }

    if (!st.empty())
        return false;

    return true;
}

int main()
{
    string s = "({}[)";
    cout << isValid(s) << endl;
}
