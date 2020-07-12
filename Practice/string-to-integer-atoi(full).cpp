class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1, i = 0;
        long ans = 0;
        while (s[i] == ' ' and i < s.size())
            i++;

        if (i == s.size())
            return ans;

        if (s[i] == '-' or s[i] == '+')
            sign = (s[i++] == '-') ? -1 : 1;

        for (; i < s.size(); i++)
        {
            if (s[i] >= '0' and s[i] <= '9')
            {
                ans = ans * 10 + (s[i] - '0');
                if (ans > INT_MAX)
                    return (sign == -1) ? INT_MIN : INT_MAX;
            }
            else
                break;
        }

        return sign * ans;
    }
};