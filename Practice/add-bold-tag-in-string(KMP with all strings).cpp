class Solution
{
public:
    vector<int> prefix(string pattern)
    {
        int N = pattern.size();
        vector<int> lps(N, 0);
        int j = 0;
        for (int i = 1; i < N; i++)
        {
            j = lps[i - 1];
            while (j and pattern[i] != pattern[j])
                j = lps[j - 1];

            if (pattern[i] == pattern[j])
                j++;
            lps[i] = j;
        }

        return lps;
    }
    void KMP(vector<bool> &visited, string text, string pattern)
    {
        vector<int> lps = prefix(pattern);
        int j = 0, i = 0, N = text.size(), M = pattern.size();
        while (i < N)
        {
            while (j and text[i] != pattern[j])
                j = lps[j - 1];

            if (text[i] == pattern[j])
                j++;

            i++; // next character in text
            if (j >= M)
            {
                // (as i++ has been done, i-Mth index is the starting position)
                for (int k = i - M; k < i; k++)
                    visited[k] = true;
                j = lps[j - 1];
            }
        }
    }

    string toString(char c) { return string(1, c); }

    string addBoldTag(string text, vector<string> &dict)
    {
        int N = text.size();
        vector<bool> visited(N, false);

        for (auto p : dict)
            KMP(visited, text, p);

        string result = "";
        bool boldTagStart = false;
        for (int i = 0; i < N; i++)
        {
            if (visited[i])
            {
                if (boldTagStart)
                    result += toString(text[i]);
                else
                {
                    result += "<b>" + toString(text[i]);
                    boldTagStart = true;
                }
            }
            else
            {
                if (boldTagStart)
                    result += "</b>";
                boldTagStart = false;
                result += toString(text[i]);
            }
        }
        if (boldTagStart)
            result += "</b>";
        return result;
    }
};