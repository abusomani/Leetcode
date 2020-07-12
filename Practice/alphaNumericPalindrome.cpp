class Solution
{
public:
    bool isPalindrome(string s)
    {
        int N = s.size();
        if (N == 0)
            return true;
        int i = 0, j = N - 1;
        while (i < j)
        {
            while (i < j and !isalnum(s[i]))
                i++;
            while (i < j and !isalnum(s[j]))
                j--;
            if (i < j and tolower(s[i++]) != tolower(s[j--]))
                return false;
        }
        return true;
    }
};