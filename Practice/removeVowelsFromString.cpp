class Solution
{
public:
    bool isVowel(char ch)
    {
        return (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u');
    }
    string removeVowels(string S)
    {
        string result = "";
        for (auto i : S)
            result += isVowel(i) ? "" : string(1, i);

        return result;
    }
};