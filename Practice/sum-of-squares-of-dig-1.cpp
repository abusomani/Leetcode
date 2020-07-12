//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int digitSqSum(int n)
    {
        int ans = 0;
        while (n)
        {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n)
    {
        unordered_set<int> St;
        while (true)
        {
            int val = digitSqSum(n);
            if (St.find(val) != St.end())
                return false;
            if (val == 1)
                return true;
            St.insert(val);
            n = val;
        }
        return false;
    }
};