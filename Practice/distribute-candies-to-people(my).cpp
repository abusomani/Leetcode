class Solution
{
public:
    vector<int> distributeCandies(int c, int N)
    {
        vector<int> res(N, 0);
        if (N == 1)
        {
            res[0] = c;
            return res;
        }
        int total = (N * (N + 1)) / 2, level = 0, n = c;
        while (true)
        {
            int thislevel = level * N * N + total;
            if (n >= thislevel)
                n -= thislevel, level++;
            else
            {
                for (int i = 1; i <= N; i++)
                    res[i - 1] = level * i + ((level - 1) * level * N) / 2;
                for (int i = 1; i <= N; i++)
                {
                    int x = level * N + i;
                    res[i - 1] += min(x, n), n -= min(x, n);
                }
                return res;
            }
        }
    }
};

class Solution
{
public:
    vector<int> distributeCandies(int candies, int N)
    {
        vector<int> res(N, 0);
        int i = 0, to_give = 1;
        while (candies >= 0)
        {
            res[i++] += min(candies, to_give);
            candies -= to_give++;
            i %= N;
        }
        return res;
    }
};