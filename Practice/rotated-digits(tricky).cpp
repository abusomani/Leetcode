class Solution
{
public:
    int rotatedDigits(int N)
    {
        vector<int> must_have = {0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
        vector<int> cant_have = {0, 0, 0, 1, 1, 0, 0, 1, 0, 0};
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            int m = 0, c = 0, j = i;
            while (j)
            {
                if (cant_have[j % 10])
                {
                    c++;
                    break;
                }
                m += must_have[j % 10];
                j /= 10;
            }
            if (c)
                continue;
            if (!m)
                continue;
            ans++;
        }

        return ans;
    }
};