class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> sCnt(256, 0), tCnt(256, 0);
        for (auto &c : s)
            sCnt[c]++;
        for (auto &c : t)
            tCnt[c]++;
        return sCnt == tCnt;
    }
};