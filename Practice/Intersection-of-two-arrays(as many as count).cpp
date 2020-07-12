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
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> Mp;
        vector<int> V;
        for (int num : nums1)
            Mp[num]++;
        for (int num : nums2)
            if (Mp[num]-- > 0)
                V.push_back(num);

        return V;
    }
};