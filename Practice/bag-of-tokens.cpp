class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int N = tokens.size();
        if(N == 0)return N;
        sort(tokens.begin(), tokens.end());
        if(P < tokens[0])return 0;
        int ans = 0 , l = 0, r = N-1, score = 0;
        while(l <= r) {
            while(l < N and P >= tokens[l]) {
                P -= tokens[l++];
                score++;
                ans = max(ans, score);
            }
            if(score > 0 and r > 0) {
                P += tokens[r--];
                score--;
            }
        }
        return ans;
    }
};