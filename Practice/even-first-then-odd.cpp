//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0)
                swap(A[i++], A[j]);
        return A;
    }
};