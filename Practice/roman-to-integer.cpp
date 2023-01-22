class Solution
{
private:
    vector<int> cnt;

public:
    void init()
    {
        cnt.resize(26, 0);
        cnt['I' - 'A'] = 1;
        cnt['V' - 'A'] = 5;
        cnt['X' - 'A'] = 10;
        cnt['L' - 'A'] = 50;
        cnt['C' - 'A'] = 100;
        cnt['D' - 'A'] = 500;
        cnt['M' - 'A'] = 1000;
    }
    int romanToInt(string s)
    {
        init();
        int ans = 0, N = s.size();
        for (int i = 0; i < N; i++)
        {
            if (i + 1 < N and cnt[s[i] - 'A'] < cnt[s[i + 1] - 'A'])
                ans -= cnt[s[i] - 'A'];
            else
                ans += cnt[s[i] - 'A'];
        }

        return ans;
    }
};