class Solution {
public:
    int scoreOfParentheses(string S, int idx = 0) {
        stack<int> St;
        for(auto &c: S){
            if(c == '(')
                St.push(0);
            else {
                if(St.top() == 0)
                    St.pop(),St.push(1);
                else {
                    int val = 0;
                    while(!St.empty() and St.top() != 0)
                        val += St.top(), St.pop();
                    if(!St.empty())
                        St.pop();
                    St.push(2 * val);
                }
            }
        }
        int res = 0;
        while(!St.empty())
            res += St.top(), St.pop();
        return res;
    }
};
/*
"()"
"(())"
"()()"
"(()(()))"
"(((()((())))))"
"(())()"
*/

class Solution
{
public:
    int scoreOfParentheses(string S)
    {
        int N = S.size(), l = 0, res = 0;
        for (int i = 0; i < N; i++)
        {
            if (S[i] == '(')
                l++;
            else
                l--;
            if (S[i] == ')' and S[i - 1] == '(')
                res += (1 << l);
        }
        return res;
    }
};
/*
"()"
"(())"
"()()"
"(()(()))"
"(((()((())))))"
"(())()"
*/