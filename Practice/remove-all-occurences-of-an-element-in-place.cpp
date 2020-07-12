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
    int removeElement(vector<int> &nums, int val)
    {
        int idx = 0, N = nums.size();
        for (int i = 0; i < N; i++)
            if (nums[i] != val)
                nums[idx++] = nums[i];
        return idx;
    }
};