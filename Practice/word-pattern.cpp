class Solution
{
private:
    unordered_map<char, string> Mp;
    unordered_map<string, char> RMp;

public:
    bool isPossible(string &P, vector<string> &tokens, int idx)
    {
        if (idx == tokens.size())
            return true;
        if (Mp.count(P[idx]))
            return Mp[P[idx]] == tokens[idx] ? isPossible(P, tokens, idx + 1) : false;
        else
        {
            if (RMp.count(tokens[idx]))
                return false;
            Mp[P[idx]] = tokens[idx];
            RMp[tokens[idx]] = P[idx];
            return isPossible(P, tokens, idx + 1);
        }
    }
    bool wordPattern(string pattern, string str)
    {
        vector<string> tokens;
        stringstream ss(str);
        string tmp;
        while (getline(ss, tmp, ' '))
        {
            if (tmp.empty())
                continue;
            tokens.push_back(tmp);
        }
        return tokens.size() == pattern.size() and isPossible(pattern, tokens, 0);
    }
};