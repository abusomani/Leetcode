class Solution
{
public:
    bool isPalindrome(string s)
    {
        int N = s.size();
        int l = 0, r = N - 1;
        while (l < r)
        {
            if (!isalnum(s[l]))
                l++;
            else if (!isalnum(s[r]))
                r--;
            else if (tolower(s[l]) == tolower(s[r]))
                l++, r--;
            else
                return false;
        }
        return true;
    }
};