class Solution
{
private:
    vector<int> KMP(string s)
    {
        int N = s.size();
        vector<int> lps(N, 0);
        int j = 0;
        for (int i = 1; i < N; i++)
        {
            j = lps[i - 1];
            while (j > 0 and s[i] != s[j])
                j = lps[j - 1];
            if (s[i] == s[j])
                j++;
            lps[i] = j;
        }
        return lps;
    }
    bool allCharMatch(string src, string dest)
    {
        unordered_set<char> St(dest.begin(), dest.end());
        for (auto &c : src)
            if (!St.count(c))
                return false;
        return true;
    }

public:
    int repeatedStringMatch(string A, string B)
    {
        // all characters of B should exist in A
        if (!allCharMatch(B, A))
            return -1;
        int N = A.size(), M = B.size();
        // KMP on B and then String matching with cycles
        vector<int> lps = KMP(B);
        // Either increase i by 1 else if there was a match of some characters, then i would increase
        // by the margin of (j - lps[j-1]) because those many characters were matched already.
        for (int i = 0, j = 0; i < N; i += max(1, (j ? j - lps[j - 1] : 0)), j = j ? lps[j - 1] : 0)
        {
            while (j < M and A[(i + j) % N] == B[j])
                j++;
            if (j == M)
                return ceil((float)(i + j) / N);
        }
        return -1;
    }
};