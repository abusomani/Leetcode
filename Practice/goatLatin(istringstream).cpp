class Solution
{
public:
    string toGoatLatin(string S)
    {
        unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        istringstream iss(S);
        string result, w;
        int i = 0, j;
        while (iss >> w)
        {
            result += ' ' + (vowel.count(w[0]) == 1 ? w : w.substr(1) + w[0]) + "ma";
            for (j = 0, i++; j < i; j++)
                result += "a";
        }
        return result.substr(1);
    }
};