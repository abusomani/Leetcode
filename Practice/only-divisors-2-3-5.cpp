//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isUgly(int num)
    {
        for (int i = 2; i < 6 && num; i++)
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
};