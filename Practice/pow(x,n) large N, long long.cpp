//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;
/*
pow(x, N) where  -2^31 <  N < 2^31 -1
 */

class Solution
{
public:
    double myPow(double x, int n)
    {
        long M = n;
        if (M < 0)
        {
            x = 1 / x;
            M = -M;
        }
        double ans = 1, a = x;
        while (M)
        {
            if (M & 1)
                ans *= a;
            a = a * a;
            M >>= 1;
        }

        return ans;
    }
};

class Solution
{
public:
    double pow(double x, long n)
    {
        double res = 1;
        while (n)
        {
            if (n & 1)
                res = res * x, n--;
            else
                x = x * x, n >>= 1;
        }
        return res;
    }
    double myPow(double x, int n)
    {
        long N = n;
        if (x == 0)
            return x;
        if (N == 0)
            return 1;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        return pow(x, N);
    }
};