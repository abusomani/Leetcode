class Solution
{
public:
    string minWindow(string s, string t)
    {
        int N = s.size(), M = t.size(), begin = 0, end = 0, ans = INT_MAX, counter = 0, finalStart;
        vector<int> tCnt(256, 0);
        for (auto &c : t)
            tCnt[c]++;

        while (end < N)
        {
            if (tCnt[s[end++]]-- > 0)
                counter++;

            while (counter >= M)
            {
                if (end - begin < ans)
                {
                    ans = end - begin;
                    finalStart = begin;
                }
                if (tCnt[s[begin++]]++ >= 0)
                    counter--;
            }
        }

        return ans == INT_MAX ? "" : s.substr(finalStart, ans);
    }
};