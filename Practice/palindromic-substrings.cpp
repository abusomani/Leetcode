class Solution {
private:
    int expandAroundCenter(string s, int l, int r) {
        int N = s.size(), res = 0;
        while(l >= 0 and r < N and s[l] == s[r])
            l--, r++, res++;
        return res;
    }
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i=0; i<s.size();i++)
            cnt += expandAroundCenter(s, i,i), cnt += expandAroundCenter(s, i,i+1);
        return cnt;
    }
};