class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> cnt(256, 0);
        for (auto ch : t)
            cnt[ch]++;
        int N = s.size(), begin = 0, end = 0, counter = 0, len = t.size(), ans = INT_MAX;
        string res = "";
        while (end < N)
        {
            if (cnt[s[end++]]-- > 0) // if the count is positive, implies its in t
                counter++;
            while (counter >= len)
            {
                if (end - begin < ans) // minimum requires to compute minimum at every step within inner loop
                {
                    ans = end - begin;
                    res = s.substr(begin, end - begin);
                }

                if (cnt[s[begin++]]++ == 0) // if the count becomes zero, implies it is a character in t, so counter--
                    counter--;
            }
        }
        return res;
    }
};