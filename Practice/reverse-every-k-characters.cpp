//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int idx = 0;
        while (idx < s.size())
        {
            reverse(&s[idx], (idx + k) <= s.size() ? &s[idx + k] : &s[s.size()]);
            idx += 2 * k;
        }
        return s;
    }
};