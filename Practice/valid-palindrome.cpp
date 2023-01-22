class Solution
{
public:
    bool isPalindrome(string s)
    {
        const int N = s.size();
        int i = 0, j = N - 1;
        while (i < j)
        {
            if (!isalnum(s[i]))
                i++;
            else if (!isalnum(s[j]))
                j--;
            else if (tolower(s[i]) == tolower(s[j]))
                i++, j--;
            else
                return false;
        }
        return true;
    }
};