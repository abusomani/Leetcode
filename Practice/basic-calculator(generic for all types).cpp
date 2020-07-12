/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . 
The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
*/
// Time complexity => O(N)
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
        vector<long> nums;
        char op = '+';                          // default add the number to the nums array
        for (; i < s.size() and op != ')'; i++) // if we get ) then return the sum from this level
        {
            if (s[i] == ' ')
                continue;
            long n = s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i);
            switch (op)
            {
            case '+':
                nums.push_back(n);
                break;
            case '-':
                nums.push_back(-n);
                break;
            case '*':
                nums.back() *= n;
                break;
            case '/':
                nums.back() /= n;
                break;
            }
            if (i < s.size())
                op = s[i];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
    long parseNum(string &s, int &i)
    {
        long n = 0;
        while (i < s.size() and isdigit(s[i]))
            n = 10 * n + (s[i++] - '0');
        return n;
    }
};