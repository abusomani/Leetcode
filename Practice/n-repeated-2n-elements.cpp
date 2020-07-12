//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        int i = 0, j = 0, n = A.size();
        while (i == j || A[i] != A[j])
            i = rand() % n, j = rand() % n;
        return A[i];
    }
    int repeatedNTimes1(vector<int> &A)
    {
        for (auto i = 0; i < A.size() - 2; ++i)
            if (A[i] == A[i + 1] || A[i] == A[i + 2])
                return A[i];
        return A[A.size() - 1];
    }
};