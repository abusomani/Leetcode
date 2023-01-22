class Solution
{
public:
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    string toGoatLatin(string S)
    {
        string ans, tmp, A = "a", MA = "ma";
        stringstream ss(S);
        while (getline(ss, tmp, ' '))
        {
            ans += " ";
            if (vowel.count(tolower(tmp[0])))
                ans += tmp + MA;
            else
                ans += tmp.substr(1) + tmp[0] + MA;

            ans += A;
            A += "a";
        }

        return ans.substr(1);
    }
};