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
    vector<int> sortedSquares(vector<int> &A)
    {
        int left = 0, right = 0, N = A.size();
        vector<int> V;
        if (A.size() == 0)
            return V;

        int mn_num = INT_MAX, mn_idx = 0;

        for (int i = 0; i < N; i++)
        {
            if (abs(A[i]) <= mn_num)
            {
                mn_num = abs(A[i]);
                mn_idx = i;
            }
        }

        left = mn_idx, right = mn_idx + 1;

        while (left >= 0 and right < N)
        {
            if (abs(A[left]) <= abs(A[right]))
                V.push_back(A[left] * A[left]), left--;
            else
                V.push_back(A[right] * A[right]), right++;
        }

        while (left >= 0)
            V.push_back(A[left] * A[left]), left--;

        while (right < N)
            V.push_back(A[right] * A[right]), right++;

        return V;
    }
};