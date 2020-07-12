//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> Mp;
        int ans = INT_MAX;
        for (int i = 0; i < s.size(); i++)
        {
            if (Mp.find(s[i]) == Mp.end())
                Mp[s[i]] = i;
            else
                Mp[s[i]] = INT_MAX;
        }

        for (auto it : Mp)
            ans = min(it.second, ans);

        return (ans == INT_MAX) ? -1 : ans;
    }
};