class Solution
{
public:
    // Similar to problem of finding set with interesection of size two
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;

        sort(points.begin(), points.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int p1 = points[0][1], ans = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if (p1 >= points[i][0])
                continue;
            else
            {
                p1 = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};