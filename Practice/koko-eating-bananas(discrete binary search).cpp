class Solution
{
public:
    bool isPossible(vector<int> &piles, int H, int X)
    {
        int cnt = 0;
        for (int i = 0; i < piles.size(); i++)
            cnt += (piles[i] / X) + ((piles[i] % X) ? 1 : 0);
        return cnt <= H;
    }
    int minEatingSpeed(vector<int> &piles, int H)
    {
        int mx = INT_MIN;
        for (auto p : piles)
            mx = max(p, mx);

        int l = 1, r = mx;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (isPossible(piles, H, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};