class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int N = s.size(), ans = 0, begin = 0, end = 0, counter = 0;
        vector<int> cnt(256, 0);
        while (end < N)
        {
            if (cnt[s[end++]]++ > 0) // already occured
                counter++;
            while (counter)
            {
                if (cnt[s[begin++]]-- > 1)
                    counter--;
            }
            ans = max(ans, end - begin);
        }

        return ans;
    }
};