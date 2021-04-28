class Solution {
public:
    int countLetters(string S) {
        int res = 0, cnt = 1;
        for(int i=1; i<S.size(); i++) {
            if(S[i] != S[i-1]) {
                res += (cnt * (cnt+1))/2;
                cnt = 1;
            }
            else
                cnt++;
        }
        res += (cnt * (cnt+1))/2;
        return res;
    }
};