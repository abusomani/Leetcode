//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        vector<vector<int>> V(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            int sz = A[i].size();
            for (int j = sz - 1; j >= 0; j--)
                V[i].push_back(!A[i][j]);
        }
        return V;
    }
};