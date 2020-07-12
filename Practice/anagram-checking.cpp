//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> V(256, 0);
        for (int i = 0; i < s.size(); i++)
            V[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++)
            V[t[i] - 'a']--;
        for (int i = 0; i < 256; i++)
            if (V[i])
                return false;

        return true;
    }
};