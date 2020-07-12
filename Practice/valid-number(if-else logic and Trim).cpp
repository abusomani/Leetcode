/*
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
*/
class Solution
{
public:
    // trim from start
    static inline string &ltrim(string &s)
    {
        s.erase(s.begin(), find_if(s.begin(), s.end(),
                                   not1(ptr_fun<int, int>(isspace))));
        return s;
    }

    // trim from end
    static inline string &rtrim(string &s)
    {
        s.erase(find_if(s.rbegin(), s.rend(),
                        not1(ptr_fun<int, int>(isspace)))
                    .base(),
                s.end());
        return s;
    }

    // trim from both ends
    static inline string &trim(string &s)
    {
        return ltrim(rtrim(s));
    }
    bool isNumber(string s)
    {
        trim(s);
        if (s.size() <= 0)
            return false;

        bool eSeen = false;
        bool dotSeen = false;
        bool numberBeforeE = false, numberAfterE = false;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch >= '0' and ch <= '9')
            {
                if (eSeen)
                    numberAfterE = true;
                else
                    numberBeforeE = true;
            }
            else if (ch == '+' or ch == '-')
            {
                if (i != 0 && s[i - 1] != 'e') // 6e-1
                    return false;
            }
            else if (ch == '.')
            {
                if (eSeen or dotSeen)
                    return false;
                dotSeen = true;
            }
            else if (ch == 'e')
            {
                if (eSeen)
                    return false;
                eSeen = true;
            }
            else // invalid characters
                return false;
        }

        return (eSeen) ? (numberBeforeE and numberAfterE) : numberBeforeE;
    }
};