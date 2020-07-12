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
    int findDuplicate(vector<int> &nums)
    {
        int low = 1, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (int)(low + (high - low) * 0.5);
            int cnt = 0;
            for (int a : nums)
            {
                if (a <= mid)
                    ++cnt;
            }
            if (cnt <= mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};