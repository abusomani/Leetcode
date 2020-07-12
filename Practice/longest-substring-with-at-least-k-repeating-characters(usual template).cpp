class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int ans = 0;
        for (int numUniqueTarget = 1; numUniqueTarget <= 26; numUniqueTarget++)
            ans = max(ans, longestSubstringWithNUniqueChars(s, k, numUniqueTarget));

        return ans;
    }

    int longestSubstringWithNUniqueChars(string s, int k, int numUniqueTarget)
    {
        vector<int> map(256, 0);
        int numUnique = 0;      // counter 1
        int numNoLessThanK = 0; // counter 2
        int begin = 0, end = 0, ans = 0, N = s.size();

        while (end < N)
        {
            if (map[s[end]]++ == 0) // increment map[c] after this statement
                numUnique++;
            if (map[s[end++]] == k) // inc end after this statement
                numNoLessThanK++;

            while (numUnique > numUniqueTarget)
            {
                if (map[s[begin]]-- == k) // decrement map[c] after this statement
                    numNoLessThanK--;
                if (map[s[begin++]] == 0)
                    numUnique--;
            }

            // if we found a string where the number of unique chars equals our target
            // and all those chars are repeated at least K times then update max
            if (numUnique == numUniqueTarget && numUnique == numNoLessThanK)
                ans = max(end - begin, ans);
        }

        return ans;
    }
};