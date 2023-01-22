class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> St;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '(')
                St.push(i);
            else if (c == ')')
            {
                if (!St.empty())
                    St.pop();
                else
                    s[i] = '*';
            }
        }
        while (!St.empty())
        {
            s[St.top()] = '*';
            St.pop();
        }
        string result = "";
        for (auto &c : s)
            if (c != '*')
                result += c;

        return result;
    }
};