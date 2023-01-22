class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int N = costs.size();
        if (N == 0)
            return 0;

        int r = costs[0][0], b = costs[0][1], g = costs[0][2], rr, bb, gg;
        for (int i = 1; i < N; i++)
        {
            rr = r;
            bb = b;
            gg = g;
            r = min(bb, gg) + costs[i][0]; // if ith house is painted with 0th color
            b = min(rr, gg) + costs[i][1]; // if ith house is painted with 0th color
            g = min(rr, bb) + costs[i][2]; // if ith house is painted with 0th color
        }

        return min(r, min(b, g));
    }
};