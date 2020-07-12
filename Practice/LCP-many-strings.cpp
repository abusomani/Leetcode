//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &V)
    {
        if (V.size() == 0)
            return "";

        string common = V[0];
        for (int i = 1; i < V.size(); i++)
        {
            string newC = "";
            int j = 0, k = 0;
            while (j < V[i].size() and k < common.size())
            {
                if (V[i][j] == common[k])
                    newC += V[i][j++], k++;
                else
                    break;
            }
            common = newC;

            if (common.size() == 0)
                return "";
        }
        return common;
    }
};