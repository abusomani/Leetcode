/*
For each element in s
If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
If not match, then we check if there is a * previously showed up,
       if there is no *,  return false;
       if there is an *,  we set current p to the next element of *, and set current s to the next saved s position.

e.g.

abed
?b*d**

a=?, go on, b=b, go on,
e=*, save * position star=3, save s position ss = 3, p++
e!=d,  check if there was a *, yes, ss++, s=ss; p=star+1
d=d, go on, meet the end.
check the rest element in p, if all are *, true, else false;
*/
class Solution
{
public:
    string cleanup(string p)
    {
        string str = "#";
        for (auto c : p)
        {
            if (c == '*' and str.back() == '*')
                continue;
            str += c;
        }
        return str.substr(1);
    }
    bool isMatch(string str, string pattern)
    {
        pattern = cleanup(pattern); // reduces time complexity significantly
        int s = 0, p = 0, match = 0, starIdx = -1;
        while (s < str.size())
        {
            // advancing both pointers
            if (p < pattern.size() && (pattern[p] == '?' || str[s] == pattern[p]))
            {
                s++;
                p++;
            }
            // * found, only advancing pattern pointer
            else if (p < pattern.size() && pattern[p] == '*')
            {
                starIdx = p;
                match = s;
                p++;
            }
            // last pattern pointer was *, advancing string pointer
            else if (starIdx != -1) // its like Naive NxM match
            {
                /* test case
                "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                "*aaaaaab"
                */
                p = starIdx + 1;
                match++;
                s = match;
            }
            //current pattern pointer is not star, last patter pointer was not *
            //characters do not match
            else
                return false;
        }

        //check for remaining characters in pattern
        while (p < pattern.size() && pattern[p] == '*')
            p++;

        return p == pattern.size();
    }
};