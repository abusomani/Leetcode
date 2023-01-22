class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int N = cardPoints.size();
        vector<int> prefix = {0};
        for (auto &i : cardPoints)
            prefix.push_back(prefix.back() + i);
        int Total = prefix.back(), mx = INT_MAX;
        if (k == N)
            return Total;
        int l = 0, r = N - k;
        while (r <= N)
            mx = min(mx, prefix[r++] - prefix[l++]);
        return Total - mx;
    }
};