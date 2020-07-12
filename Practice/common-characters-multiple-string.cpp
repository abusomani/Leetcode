//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<string> res;
        vector<int> cnt(26, INT_MAX);

        for (string str : A)
        {
            vector<int> cnt1(26, 0);
            for (char ch : str)
                cnt1[ch - 'a']++;
            for (int i = 0; i < 26; i++)
                cnt[i] = min(cnt[i], cnt1[i]);
        }

        for (int i = 0; i < 26; i++)
            for (int j = 0; j < cnt[i]; j++)
                res.push_back(string(1, i + 'a'));

        return res;
    }
};