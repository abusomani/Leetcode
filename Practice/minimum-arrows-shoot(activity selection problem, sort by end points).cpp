//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool customComp(vector<int> a, vector<int> b)
    {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), customComp);
        int ans = 0, arrow = -1;

        for (int i = 0; i < points.size(); i++)
        {
            if (arrow != -1 and points[i][0] <= arrow)
                continue;
            arrow = points[i][1];
            ans++;
        }

        return ans;
    }
};