//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans = 0, N = nums.size();
        for (int i = 0; i < N; i++)
            ans ^= i ^ nums[i];

        return (ans ^ N);
    }
};