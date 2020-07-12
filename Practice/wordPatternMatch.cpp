class Solution
{
public:
    bool wordPatternMatch(string pattern, string str)
    {
        unordered_map<char, string> Mp;
        unordered_set<string> St;
        return helper(pattern, 0, str, 0, Mp, St);
    }

private:
    bool helper(string pattern, int i, string str, int j, unordered_map<char, string> &Mp,
                unordered_set<string> &St)
    {
        if (i == pattern.size() or j == str.size())
            return (i == pattern.size() and j == str.size());

        char ch = pattern[i];
        for (int idx = j; idx < str.size(); idx++)
        {
            string substr = str.substr(j, idx - j + 1);       // idx is kind of index, so (idx - j + 1) characters
            if (Mp.find(ch) != Mp.end() and Mp[ch] == substr) // if ch is mapped to the new substr already then recurse for index idx+1
            {
                if (helper(pattern, i + 1, str, idx + 1, Mp, St))
                    return true;
            }
            if (Mp.find(ch) == Mp.end() and St.find(substr) == St.end()) // does not map to other character
            {
                Mp[ch] = substr;
                St.insert(substr);
                if (helper(pattern, i + 1, str, idx + 1, Mp, St))
                    return true;
                Mp.erase(ch);
                St.erase(substr);
            }
        }
        return false;
    }
};