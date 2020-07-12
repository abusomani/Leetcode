class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        int n = cells.size(), cycle = 0;
        vector<int> cur(n, 0), direct;
        while (N-- > 0)
        {
            for (int i = 1; i < n - 1; ++i)
                cur[i] = cells[i - 1] == cells[i + 1];
            if (direct.empty())
                direct = cur;
            else if (direct == cur)
                N %= cycle;

            ++cycle;
            cells = cur;
        }
        return cur;
    }
};