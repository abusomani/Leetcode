//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int findShortestSubArray(vector<int> &nums)
{
    unordered_map<int, int> counter, first;
    int res = 0, degree = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (first.count(nums[i]) == 0)
            first[nums[i]] = i;
        if (++counter[nums[i]] > degree)
        {
            degree = counter[nums[i]];
            res = i - first[nums[i]] + 1;
        }
        else if (counter[nums[i]] == degree)
            res = min(res, i - first[nums[i]] + 1);
    }
    return res;
}