//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> pv(256, 0), sv(256, 0), res;
        if (s.size() < p.size())
            return res;
        for (int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]];
            ++sv[s[i]];
        }
        if (pv == sv)
            res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i)
        {
            ++sv[s[i]];
            --sv[s[i - p.size()]];
            if (pv == sv) // this comparison takes O(256), i.e O(1), since both vectors are of fixed size 256. Total complexity O(n)*O(1) = O(n)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};