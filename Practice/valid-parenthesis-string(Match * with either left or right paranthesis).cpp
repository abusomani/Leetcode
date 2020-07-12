class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> Mp;
    bool isValid(string s, int pos, int open)
    {
        if (Mp.count(pos) and Mp[pos].count(open))
            return Mp[pos][open];

        if (open < 0) // more closed brackets
            return Mp[pos][open] = false;

        if (pos == s.size())
            return Mp[pos][open] = (open == 0);

        if (s[pos] == '(')
            return Mp[pos][open] = isValid(s, pos + 1, open + 1);
        if (s[pos] == ')')
        {
            if (open <= 0) // if no open brace found then definitely wrong
                return Mp[pos][open] = false;

            return Mp[pos][open] = isValid(s, pos + 1, open - 1);
        }

        return Mp[pos][open] = (isValid(s, pos + 1, open + 1) or isValid(s, pos + 1, open - 1) or isValid(s, pos + 1, open));
    }
    bool checkValidString(string s)
    {
        return isValid(s, 0, 0);
    }
};