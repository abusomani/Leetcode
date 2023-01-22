class Solution
{
public:
    bool isRepeating(int len, string &S)
    {
        for (int i = 0; i <= S.size() - len; i++)
        {
            string sub_str = S.substr(i, len);
            // from the very next position
            if (S.find(sub_str, i + 1) != string::npos)
                return true;
        }
        return false;
    }
    int longestRepeatingSubstring(string S)
    {
        int N = S.size(), l = 0, r = N - 1, ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isRepeating(mid, S))
                ans = max(ans, mid), l = mid + 1;
            else
                r = mid - 1;
        }
        return ans;
    }
};