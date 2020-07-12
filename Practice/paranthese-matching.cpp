#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> St;
        map<char, char> Mp;
        Mp[')'] = '(';
        Mp['}'] = '{';
        Mp[']'] = '[';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[')
                St.push(s[i]);
            else if (!St.empty() and St.top() == Mp[s[i]]) // let say string is only "]", assure St.empty
                St.pop();
            else
                return false;
        }

        if (St.empty())
            return true;
        return false;
    }
};