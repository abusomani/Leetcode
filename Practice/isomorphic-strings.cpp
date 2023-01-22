class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> MpS, MpT;
        int N = s.size();
        for (int i = 0; i < N; i++)
        {
            // mapping already exists
            if (MpS.count(s[i]) and MpS[s[i]] != t[i])
                return false;
            // mapping already exists
            if (MpT.count(t[i]) and MpT[t[i]] != s[i])
                return false;
            MpS[s[i]] = t[i];
            MpT[t[i]] = s[i];
        }

        return true;
    }
};