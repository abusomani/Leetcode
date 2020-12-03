class Solution {
public:
    string mul(int n, string s) {
        string res;
        while(n--)
            res += s;
        return res;
    }
    string decodeString(string s) {
        int idx = 0;
        return gen(s, idx);
    }
    string gen(string s, int &idx) {
        string res;
        int num = 0 , N = s.size();
        while(idx < N) {
            char c = s[idx];
            num = isdigit(c) ? number(s, idx) : 0;
            if(idx >= N)
                return "";
            if(s[idx] >= 'a' and s[idx] <= 'z')
                res += s[idx++];
            else if(s[idx] == '[')
                res += mul(num, gen(s, ++idx));
            else if(s[idx] == ']')
            {
                idx++;
                return res;
            }
            
        }
        return res;
    }
    int number(string s, int &i) {
        int num = 0, N = s.size();
        while(i < N and isdigit(s[i]))
            num = num * 10 + (s[i++] - '0');
        return num;
    }
};