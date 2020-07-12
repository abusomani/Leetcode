/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
class Solution
{
public:
    string decodeString(string s)
    {
        int i = 0;
        return parseExpr(s, i);
    }
    string parseExpr(string &s, int &i)
    {
        string res;
        for (; i < s.size() and s[i] != ']';)
        {
            if (!isdigit(s[i]))
                res += s[i++];
            else
            {
                int n = parseNum(s, i);
                i++; // '['
                string next = parseExpr(s, i);
                i++; // ']'

                while (n--)
                    res += next;
            }
        }

        return res;
    }
    int parseNum(string &s, int &i)
    {
        int n = 0;
        while (i < s.size() and isdigit(s[i]))
            n = 10 * n + (s[i++] - '0');
        return n;
    }
};