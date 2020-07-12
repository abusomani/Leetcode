#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
    Always take long long, reverse number logic
*/
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x == 0)
            return true;
        else if (x < 0)
            return false;

        ll temp = x;
        ll newAns = 0;
        while (temp)
        {
            newAns = newAns * 10 + temp % 10;
            temp /= 10;
        }

        if (x == newAns)
            return true;
        return false;
    }
};
