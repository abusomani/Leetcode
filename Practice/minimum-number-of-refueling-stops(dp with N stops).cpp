#define ll long long
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& A) {
        int N = A.size();
        vector<ll> dp(N+1); // maximum distance we can get with i stops
        dp[0] = startFuel; // with 0 stops
        
        for(int i=0; i<N; i++){
            for(int stops=i; stops >= 0; stops--){
                if(dp[stops] >= A[i][0])
                    dp[stops+1] = max(dp[stops+1], dp[stops] + (ll)A[i][1]);
            }
        }
        
        for(int i=0; i<=N; i++)
            if(dp[i] >= target)
                return i;
        return -1;
    }
};