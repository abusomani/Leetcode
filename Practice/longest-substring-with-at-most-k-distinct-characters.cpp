class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int N = s.size(), begin = 0, end = 0, ans = 0;
        unordered_map<char, int> Mp;
        while (end < N)
        {
            Mp[s[end++]]++;
            // implies more than K distinct characters
            while (Mp.size() > k)
            {
                Mp[s[begin++]]--;
                // if count of character at begin-1 becomes 0, then we should erase it from the map
                if (Mp[s[begin - 1]] == 0)
                    Mp.erase(s[begin - 1]);
            }
            ans = max(ans, end - begin);
        }
        return ans;
    }
};