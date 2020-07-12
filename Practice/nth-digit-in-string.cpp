//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

/*
    9 , 90, 900 numbers of xth digit
    so problem is three parts :
        1. Number of digits it will have
        2. Which number it is
        3. Which digit of number it is
    To find number of digits :
    Keep subtracting (9 * pow(10, digits) * digits)
    Also keep a range_start for the starting range
    expected number = range_start + the N left / digits
 */

#define ll long long
class Solution
{
public:
    int findNthDigit(int N)
    {
        ll base = 9, digits = 1;
        ll range_start = 1;

        while (N - base * digits > 0)
        {
            range_start *= 10;
            N -= base * digits;
            base *= 10;
            digits++;
        }

        ll exp_num = range_start + (N - 1) / digits;

        vector<int> vec;
        while (exp_num)
        {
            vec.push_back(exp_num % 10);
            exp_num /= 10;
        }

        reverse(vec.begin(), vec.end());

        return vec[(N - 1) % digits];
    }
};
// END OF SOURCE CODE