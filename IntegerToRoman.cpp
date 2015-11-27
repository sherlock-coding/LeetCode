/*
 * 12 Integer to Roman
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 * */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string intToRoman(int num) 
{
    vector<string> sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> value{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ret;

    for (int i = 0;num > 0 && i < value.size(); ++i) {
        while ( num >= value[i]) {
            num -= value[i];
            ret += sym[i];
        }
    }

    return ret;
}

int main()
{
    cout << intToRoman(345) << endl;
}
