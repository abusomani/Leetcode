class Solution {
public:
    bool isValid(string s) {
        stack<char> St;
        for(auto &c: s) {
            if(c == '(' or c == '{' or c == '[')
                St.push(c);
            else {
                if(St.empty())return false;
                if(c == ')' and St.top() != '(')return false;
                else if(c == '}' and St.top() != '{')return false;
                else if(c == ']' and St.top() != '[')return false;
                St.pop();
            }
        }
        return St.empty();
    }
};