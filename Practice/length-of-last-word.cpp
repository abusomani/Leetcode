class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;
        stringstream ss(s);
        string tmp;
        while (getline(ss, tmp, ' '))
            if (!tmp.empty())
                ans = tmp.size();

        return ans;
    }
};