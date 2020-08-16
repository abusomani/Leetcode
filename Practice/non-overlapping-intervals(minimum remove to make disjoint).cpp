class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return (a[1] == b[1]) ? a[0] > b[0] : a[1] < b[1];
    }
    bool isOverlap(vector<int> &a, vector<int> &b)
    {
        return (a[1] > b[0] and a[1] <= b[1]) or (b[0] < a[1] and b[0] >= a[0]);
    }
    // Greedy, sort by ending time and shorter length interval.
    int eraseOverlapIntervals(vector<vector<int>> &I)
    {
        int N = I.size();
        if (N <= 1)
            return 0;
        sort(I.begin(), I.end(), comp);
        vector<vector<int>> res;
        int i = 0;
        while (i < N)
        {
            if (res.empty())
                res.push_back(I[i]);
            else if (!isOverlap(res.back(), I[i]))
            {
                res.push_back(I[i]);
            }
            i++;
        }
        return (N - res.size());
    }
};