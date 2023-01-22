class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int L = 0, idx = 0, N = S.size();
        for(int i=0; i<N; i++){
            char c = S[i];
            if(c == '(')
                L++;
            else
                L--;
            if(L == 0)
                res += S.substr(idx+1, i-idx-1), idx = i+1;
        }
        return res;        
    }
};