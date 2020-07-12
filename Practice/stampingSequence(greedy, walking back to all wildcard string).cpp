class Solution
{
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> result;
        string aim(target.size(), '*');
        while (target != aim)
        {
            int x = remove(target, stamp);
            if (x == target.size())
                return target != aim ? vector<int>() : result;
            result.push_back(x);
        }
        reverse(result.begin(), result.end());
        return result;
        ;
    }

private:
    int remove(string &str, string stamp)
    {
        for (int i = 0; i < str.size(); i++)
        {
            int l = i, r = 0;
            bool atLeastOneChar = false;
            while (l < str.size() and r < stamp.size())
            {
                if (str[l] == '*' or (str[l] == stamp[r]))
                {
                    atLeastOneChar |= (str[l] != '*');
                    l++;
                    r++;
                }
                else
                    break;
            }
            if (atLeastOneChar and r == stamp.size())
            { // whole stamp matched
                int cnt = stamp.size();
                while (cnt--)
                {
                    str[i + cnt] = '*';
                }
                return i;
            }
        }

        return str.size();
    }
};