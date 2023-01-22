class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        vector<char> A, B;
        for (auto &c : S)
        {
            if (c == '#' and !A.empty())
                A.pop_back();
            else if (c != '#')
                A.push_back(c);
        }
        for (auto &c : T)
        {
            if (c == '#' and !B.empty())
                B.pop_back();
            else if (c != '#')
                B.push_back(c);
        }
        return A == B;
    }
};