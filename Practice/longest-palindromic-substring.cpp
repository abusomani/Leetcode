class Solution {
private:
    string traverse(string s, int l, int r) {
        int N = s.size();
        int x = -1, y = -1;
        while(l >=0 and r < N and s[l] == s[r]) {
            x = l;
            y = r;
            l--;
            r++;
        }
        if(x == -1 or y == -1)
            return "";
        return s.substr(x, y-x+1);
    }
public:
    string longestPalindrome(string s) {
        int mx_len = 0, N = s.size();
        string res;
        for(int i=0; i<N; i++) {
            string tmp = traverse(s, i, i);
            if(tmp.size() > res.size())
                res = tmp;
            tmp = traverse(s, i, i+1);
            if(tmp.size() > res.size())
                res = tmp;
        }
        return res;
    }
};