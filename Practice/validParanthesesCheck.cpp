class Solution
{
private:
    unordered_map<char, char> Mp;

public:
    void init()
    {
        Mp[')'] = '(';
        Mp['}'] = '{';
        Mp[']'] = '[';
    }
    bool isValid(string s)
    {
        init();
        stack<int> St;
        for (auto c : s)
        {
            if (!Mp.count(c))
                St.push(c);
            else
            {
                if (St.empty())
                    return false;
                else if (St.top() != Mp[c])
                    return false;
                else
                    St.pop();
            }
        }

        return St.size() == 0;
    }
};