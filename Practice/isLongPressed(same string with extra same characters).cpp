//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isLongPressedName(string name, string typed, int i = 0, int j = 0)
    {
        while (j < typed.size())
        {
            if (i < name.size() && name[i] == typed[j])
                ++i, ++j;
            else if (i > 0 && name[i - 1] == typed[j])
                ++j;
            else
                return false;
        }
        return i == name.size();
    }
};