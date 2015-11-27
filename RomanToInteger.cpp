/*
 * 13 Roman to Integer
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 * */

#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

int romanToInt(string s)
{
    map<char, int> m;
    m.insert(make_pair('I', 1));
    m.insert(make_pair('V', 5));
    m.insert(make_pair('X', 10));
    m.insert(make_pair('L', 50));
    m.insert(make_pair('C', 100));
    m.insert(make_pair('D', 500));
    m.insert(make_pair('M', 1000));

    int ret = m[s[0]];
    for (int i = 1; i < s.size(); ++i) {
        ret += m[s[i]];
        if (m[s[i]] > m[s[i-1]])
            ret -= 2 * m[s[i-1]];
    }

    return ret;
}

int main()
{

}
