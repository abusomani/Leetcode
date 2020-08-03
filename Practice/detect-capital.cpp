class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int N = word.size();
        bool allCaps = true, allLower = true;
        for (int i = 0; i < N; i++)
        {
            allCaps = allCaps and isupper(word[i]);
            if (i)
                allLower = allLower and islower(word[i]);
        }
        return (allLower or allCaps);
    }
};