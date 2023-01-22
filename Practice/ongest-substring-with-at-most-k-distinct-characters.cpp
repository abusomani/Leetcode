class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        unordered_map<char, int> Mp;
        int begin = 0, end = 0, N = s.size(), ans = 0;
        while (end < N)
        {
            Mp[s[end++]]++;
            while (Mp.size() > k)
            {
                Mp[s[begin++]]--;
                if (Mp[s[begin - 1]] == 0)
                    Mp.erase(s[begin - 1]);
            }
            ans = max(ans, end - begin);
        }
        return ans;
    }
};