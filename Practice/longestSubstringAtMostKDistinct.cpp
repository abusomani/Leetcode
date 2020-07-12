class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int K)
    {
        int N = s.size(), counter = 0, maxLen = 0, begin = 0, end = 0;
        unordered_map<char, int> Mp;

        while (end < N)
        {
            Mp[s[end++]]++;
            if (Mp.size() > K)
                counter++;
            while (counter > 0)
            {
                Mp[s[begin]]--;
                if (Mp[s[begin]] == 0)
                    Mp.erase(s[begin]);
                begin++;
                if (Mp.size() <= K)
                    counter--;
            }

            maxLen = max(maxLen, end - begin);
        }

        return maxLen;
    }
};