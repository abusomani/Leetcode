//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        vector<int> V;
        int left = 0, right = S.size();
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == 'I')
                V.push_back(left++);
            else
                V.push_back(right--);
        }
        V.push_back(left);
        return V;
    }
};