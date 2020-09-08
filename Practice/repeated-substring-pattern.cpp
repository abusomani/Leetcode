class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0)
            return true;
        string newS = (s + s).substr(1, 2 * s.size() - 2);
        cout << newS << endl;
        return newS.find(s) != string::npos;
    }
};
class Solution
{
private:
    vector<int> KMP(string &s)
    {
        int N = s.size(), j = 0;
        vector<int> lps(N, 0);
        for (int i = 1; i < N; i++)
        {
            j = lps[i - 1];
            while (j and s[i] != s[j])
                j = lps[j - 1];
            if (s[i] == s[j])
                j++;
            lps[i] = j;
        }
        return lps;
    }
    bool isValid(string &s, int len)
    {
        string possible = s.substr(0, len);
        int i = 0, N = s.size();
        while (i < N)
        {
            string newS = s.substr(i, len);
            if (newS != possible)
                return false;
            i += len;
        }
        return true;
    }

public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0)
            return true;
        // string newS = (s + s).substr(1, 2*s.size()-2);
        // cout << newS << endl;
        // return newS.find(s) != string::npos;
        vector<int> lps = KMP(s);
        int expected = s.size() - lps.back();
        return lps.back() and expected and isValid(s, expected);
    }
};