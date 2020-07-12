class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> cnt(256, 0);
        for (auto c : s)
            cnt[c]++;
        vector<int> oddCnt;
        int ans = 0;
        for (int i = 0; i < 256; i++)
        {
            if (cnt[i] & 1)
                oddCnt.push_back(cnt[i]);
            else
                ans += cnt[i];
        }
        if (oddCnt.size() <= 1)
            ans += (oddCnt.size() < 1) ? 0 : oddCnt[0];
        else
        {
            for (int i = 0; i < oddCnt.size(); i++)
                ans += (oddCnt[i] - 1);
            ans++;
        }

        return ans;
    }
};