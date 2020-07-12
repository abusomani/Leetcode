class Solution
{
public:
    int calculateTime(string keyboard, string word)
    {
        int cnt[26] = {0};
        for (int i = 0; i < 26; i++)
            cnt[keyboard[i] - 'a'] = i;

        int prev = keyboard[0] - 'a', ans = 0, idx;
        for (auto letter : word)
        {
            idx = letter - 'a';
            ans += abs(cnt[idx] - cnt[prev]);
            prev = idx;
        }

        return ans;
    }
};