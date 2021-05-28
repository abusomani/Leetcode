class Solution {
private:
    int eval(int A, int B, string op){
        if(op == "+")
            return A + B;
        else if(op == "-")
            return A - B;
        else if(op == "*")
            return A * B;
        else
            return A / B;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> St;
        for(auto token : tokens){
            if(token.size() == 1 and !isdigit(token[0])){
                int B = St.top(); St.pop();
                int A = St.top(); St.pop();
                St.push(eval(A, B, token));
            } else {
                St.push(token[0] == '-' ? -1 * stoi(token.substr(1)) : stoi(token));
            }
        }
        return St.top();
    }
};