/*
Check from left to right and then check from right to left.
When check from left to right, take all '*'s as '(', to see whether can match all ')'s.
And, When check from right to left, take all '*'s as ')', to see whether can match all '('s.
If both checks are valid, then the string is valid.
*/
class Solution
{
public:
    bool checkValidString(string s)
    {
        int leftBalance = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] == '(') || (s[i] == '*'))
                leftBalance++;
            else
                leftBalance--;

            if (leftBalance < 0)
                return false; // We know we have unbalanced parenthesis
        }

        // We can already check if parenthesis are valid
        if (leftBalance == 0)
            return true;

        int rightBalance = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if ((s[i] == ')') || (s[i] == '*'))
                rightBalance++;
            else
                rightBalance--;

            if (rightBalance < 0)
                return false; // We know we have unbalanced parenthesis
        }

        // Here we know we have never came across an unbalanced parsing from left to right e.g. ')('
        // We've also already substituted '*' either by '(' or by ')'
        // So we only have 3 possible scenarios here:
        // 1. We had the same amount of '(' and ')'
        // 2. We had more '(' then ')' but enough '*' to substitute
        // 3. We had more ')' then '(' but enough '*' to substitute
        return true;
    }
};