//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;
/*
    hasBit = (n & (1<<i)) != 0 (numbers can be negative)
*/
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        int bitCount[32];
        int k = 3;
        for (int i = 0; i < 32; i++)
            bitCount[i] = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            int n = nums[j];
            for (int i = 0; i < 32; i++)
            {
                int hasBit = (n & (1 << i)) != 0;
                if (hasBit)
                {
                    bitCount[i] = (bitCount[i] + 1) % k;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bitCount[i] > 0)
            {
                ans |= (1 << i);
            }
        }

        return ans;
    }

    int singleNumberSimple(int A[], int n)
    {
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((A[j] >> i) & 1)
                    count[i]++;
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }
};