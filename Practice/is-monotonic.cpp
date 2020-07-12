//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        if (A.size() <= 2)
            return true;
        bool isIncrease = A[0] <= A[A.size() - 1];
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (isIncrease and A[i] > A[i + 1])
                return false;
            else if (!isIncrease and A[i] < A[i + 1])
                return false;
        }
        return true;
    }
};