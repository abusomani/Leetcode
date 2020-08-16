class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> Mp;
        for (auto &c : s)
            Mp[c]++;
        int len = 0;
        bool oddCnt = 0;
        for (auto &i : Mp)
        {
            if (i.second & 1)
                len += i.second - 1, oddCnt = true;
            else
                len += i.second;
        }
        return len + oddCnt;
    }
};