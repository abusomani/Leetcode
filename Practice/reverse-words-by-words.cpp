//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int idx = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (i == s.size() or s[i] == ' ')
            {
                reverse(&s[idx], &s[i]);
                idx = i + 1;
            }
        }
        return s;
    }
};