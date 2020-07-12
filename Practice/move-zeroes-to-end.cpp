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
    void moveZeroes(vector<int> &nums)
    {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                nums[idx++] = nums[i];
        for (int i = idx; i < nums.size(); i++)
            nums[i] = 0;
    }
};