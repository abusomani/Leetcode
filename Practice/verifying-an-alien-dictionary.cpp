class Solution
{
private:
    unordered_map<char, int> Mp;

public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        if (words.size() == 1)
            return true;

        for (int i = 0; i < order.size(); i++)
            Mp[order[i]] = i;
        for (int i = 1; i < words.size(); i++)
            if (!compare(words[i - 1], words[i]))
                return false;

        return true;
    }

    bool compare(string A, string B)
    {
        const int N = A.size(), M = B.size();
        int i = 0, j = 0;
        while (i < N and j < M)
        {
            if (A[i] == B[j]) // important, while equal go ahead
            {
                i++;
                j++;
                continue;
            }
            if (Mp[A[i]] > Mp[B[j]]) // if different compare Map values and decision would be taken instantly
                return false;
            else
                return true;
        }
        if (i < N and j >= M) // if all chararacters same and first string is longer, then not sorted
            return false;
        return true;
    }
};