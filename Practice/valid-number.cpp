class Solution
{
public:
    string trimSpace(string s)
    {
        int N = s.size(), i = 0, j = N - 1;
        while (i < N and s[i] == ' ')
            i++;
        while (j >= 0 and s[j] == ' ')
            j--;
        return s.substr(i, j - i + 1);
    }
    bool isNumber(string s)
    {
        s = trimSpace(s);
        const int N = s.size();
        bool dotSeen = false, eSeen = false, numberBeforeE = false, numberAfterE = false;
        for (int i = 0; i < N; i++)
        {
            if (isdigit(s[i]))
            {
                if (eSeen)
                    numberAfterE = true;
                else
                    numberBeforeE = true;
            }
            else if (s[i] == '-' or s[i] == '+')
            {
                if (i == 0 or s[i - 1] == 'e')
                    continue;
                else
                    return false;
            }
            else if (s[i] == '.')
            {
                if (dotSeen or eSeen)
                    return false;
                dotSeen = true;
            }
            else if (s[i] == 'e')
            {
                if (eSeen)
                    return false;
                eSeen = true;
            }
            else
                return false;
        }

        return eSeen ? numberBeforeE and numberAfterE : numberBeforeE;
    }
};