/*
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
["a","b","1","2"]
*/
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0; // write
        for (int j = 1, count = 1; j <= chars.size(); j++, count++)
        { // read at j
            if (j == chars.size() or chars[j] != chars[j - 1])
            {
                chars[i++] = chars[j - 1]; // write the last seen character
                if (count >= 2)
                    for (char digit : to_string(count))
                        chars[i++] = digit;
                count = 0;
            }
        }
        return i;
    }
};