//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        //reverse(s.begin(), s.end());
        int half = s.size() >> 1, N = s.size();
        for (int i = 0; i < half; i++)
            swap(s[i], s[N - i - 1]);
    }
};