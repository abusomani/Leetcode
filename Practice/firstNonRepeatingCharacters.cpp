class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> cnt(256, -1); // -1 means not encountered
        for (int i = 0; i < s.size(); i++)
        {
            if (cnt[s[i]] != -1)
            {
                cnt[s[i]] = INT_MIN; // occured more than once
                continue;
            }
            cnt[s[i]] = i;
        }
        int idx = INT_MAX;
        for (auto i : cnt)
            idx = (i != -1 and i != INT_MIN) ? min(idx, i) : idx;

        return idx == INT_MAX ? -1 : idx;
    }
};