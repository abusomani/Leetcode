class Solution
{
public:
    unordered_map<char, int> Mp;
    bool isAlienSorted(vector<string> &words, string order)
    {
        Mp.clear();
        for (int i = 0; i < 26; i++)
            Mp[order[i]] = i;

        int N = words.size();

        for (int i = 1; i < N; i++)
            if (!compareTwoStrings(words[i - 1], words[i]))
                return false;

        return true;
    }
    // returns true if first string is smaller and false if second is smaller
    bool compareTwoStrings(const string a, const string b)
    {
        int i = 0, j = 0, N = a.size(), M = b.size();
        while (i < N and j < M)
        {
            if (a[i] == b[j])
                i++, j++;
            else if (Mp[a[i]] > Mp[b[j]])
                return false;
            else
                return true;
        }
        if (i < N and j == M)
            return false;
        return true;
    }
};