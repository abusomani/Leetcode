//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        unordered_set<char> St;
        int left = 0, ans = -1;
        for (int right = 0; right < s.size(); right++)
        {
            if (St.find(s[right]) == St.end())
                St.insert(s[right]), ans = max(ans, right - left + 1);
            else
            {
                while (left <= right and s[left] != s[right]) // remove till same characters
                    St.erase(s[left++]);
                // remove left
                St.erase(s[left++]);
                // add right
                St.insert(s[right]);

                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};