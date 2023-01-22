/*
"1 + 1"
"(1+(4+5+2)-3)+(6+8)"
"(7)-(0)+(4)"
*/
class Solution
{
public:
    int calculate(string s)
    {
        int i = 0;
        return parseExpr(s, i);
    }
    int parseExpr(string &s, int &i)
    {
        vector<long> res;
        char op = '+';
        for (; i < s.size() and op != ')'; i++)
        {
            if (s[i] == ' ')
                continue;
            long num = (s[i] == '(') ? parseExpr(s, ++i) : parseNum(s, i);
            switch (op)
            {
            case '+':
                res.push_back(num);
                break;
            case '-':
                res.push_back(-num);
                break;
            case '*':
                res.back() *= num;
                break;
            case '/':
                res.back() /= num;
                break;
            }
            if (i < s.size())
                op = s[i];
        }
        return accumulate(res.begin(), res.end(), 0);
    }
    long parseNum(string &s, int &i)
    {
        long num = 0;
        while (i < s.size() and isdigit(s[i]))
            num = num * 10 + (s[i++] - '0');
        return num;
    }
};