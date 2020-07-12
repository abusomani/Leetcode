//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        vector<int> V(256, -1);
        int ans = -1, start = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (V[s[i]] > start)
                start = max(start, V[s[i]]);
            V[s[i]] = i;
            ans = max(ans, i - start);
        }

        return ans;
    }
};