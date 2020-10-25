const int MAX = 1e5+5;
class Solution {
private:
    vector<bool> dp;
public:
    bool winnerSquareGame(int n) {
        dp.resize(n+1);
        dp[0] = false; // default winning for Bob
        for(int i=1; i<=sqrt(n); i++) // all the squared numbers are true, alice wins
            dp[i*i] = true;
        
        for(int i=2; i<=n; i++) {
            bool possible = false;
            for(int v=1; v<=sqrt(i); v++) {
                int val = v*v;
                if(val <= i)
                    possible |= dp[i-val] == false; // if we can move Bob to losing state
                else
                    break;
            }
            dp[i] = possible;
        }
        return dp[n];
    }
};