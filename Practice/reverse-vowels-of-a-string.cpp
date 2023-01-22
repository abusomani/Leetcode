class Solution
{
private:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

public:
    bool isVowel(char c)
    {
        for (int i = 0; i < vowels.size(); i++)
            if (vowels[i] == tolower(c))
                return true;

        return false;
    }
    string reverseVowels(string s)
    {
        int N = s.size();
        if (N == 0)
            return s;
        int i = 0, j = N - 1;
        while (i < j)
        {
            if (!isVowel(s[i]))
                i++;
            else if (!isVowel(s[j]))
                j--;
            else if (isVowel(s[i]) and isVowel(s[j]))
                swap(s[i++], s[j--]);
        }

        return s;
    }
};