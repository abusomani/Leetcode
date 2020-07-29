class Solution
{
public:
    vector<int> kmp(string &S)
    {
        int N = S.size();
        vector<int> lps(N, 0);
        for (int i = 1; i < N; i++)
        {
            int j = lps[i - 1];
            while (j and S[j] != S[i])
                j = lps[j - 1];
            if (S[i] == S[j])
                j++;
            lps[i] = j;
        }
        return lps;
    }
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        vector<int> lps = kmp(needle);
        int N = needle.size(), M = haystack.size(), i = 0, j = 0;
        while (i < M)
        {
            while (j and haystack[i] != needle[j])
                j = lps[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j >= N)
                return i - N + 1;
            i++;
        }
        return -1;
    }
};