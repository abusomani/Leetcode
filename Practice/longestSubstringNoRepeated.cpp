/*
Given a string, find the length of the longest substring without repeating characters.

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int counter = 0, maxLen = 0, N = s.size(), end = 0, begin = 0;
        vector<int> cnt(256, 0);

        while (end < N)
        {
            if (cnt[s[end++]]++ > 0)
                counter++;
            while (counter > 0)
            {
                if (cnt[s[begin++]]-- > 1)
                    counter--;
            }
            maxLen = max(maxLen, end - begin);
        }
        return maxLen;
    }
};