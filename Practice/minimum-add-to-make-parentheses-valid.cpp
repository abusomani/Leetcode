class Solution
{
public:
    int minAddToMakeValid(string S)
    {
        int left = 0, right = 0;
        for (auto &c : S)
        {
            if (c == '(')
                left++;
            else if (c == ')')
            {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }
        return left + right;
    }
};