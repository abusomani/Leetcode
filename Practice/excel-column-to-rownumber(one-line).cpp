//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int result = 0;
        for (int i = 0; i < s.size(); result = result * 26 + (s.at(i) - 'A' + 1), i++)
            ;
        return result;
    }
};