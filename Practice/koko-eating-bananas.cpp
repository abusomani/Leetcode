class Solution
{
public:
    bool isPossible(vector<int> &piles, int &N, int H, int speed)
    {
        int hours = 0;
        for (int i = 0; i < N; i++)
            hours += (piles[i] / speed) + ((piles[i] % speed != 0) ? 1 : 0);
        return hours <= H;
    }
    int minEatingSpeed(vector<int> &piles, int H)
    {
        int N = piles.size(), l = 1, r = INT_MAX;
        while (l < r)
        {
            int speed = l + ((r - l) >> 1);
            if (isPossible(piles, N, H, speed))
                r = speed;
            else
                l = speed + 1;
        }
        return l;
    }
};