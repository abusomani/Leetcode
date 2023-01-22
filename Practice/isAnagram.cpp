class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> scnt(256, 0), tcnt(256, 0);
        for (auto c : s)
            scnt[c]++;
        for (auto c : t)
            tcnt[c]++;
        return (scnt == tcnt);
    }
};