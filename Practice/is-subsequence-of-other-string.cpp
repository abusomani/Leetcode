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
    bool isSubsequence(string name, string typed)
    {
        int i = 0, j = 0, N = name.size(), M = typed.size();

        while (i < N and j < M)
        {
            if (name[i] == typed[j])
                i++;
            j++;
        }

        return (i == N);
    }
};