class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        vector<int> cnt(256, 0);
        for (auto &c : s)
            cnt[c]++;
        int oddCnt = 0;
        for (auto &i : cnt)
            if (i & 1)
                oddCnt++;

        return oddCnt <= 1;
    }
};