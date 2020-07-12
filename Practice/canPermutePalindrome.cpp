class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        if (s.size() <= 1)
            return true;

        vector<char> cnt(256, 0);
        for (char c : s)
            cnt[c]++;
        int odd = 0;
        for (int i = 0; i < 256; i++)
            if (cnt[i] & 1)
                odd++;

        return odd <= 1;
    }
};