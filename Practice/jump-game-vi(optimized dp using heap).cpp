class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> dp(N, INT_MIN);
        priority_queue<pair<int,int>> PQ;
        dp[0] = nums[0];
        PQ.push({dp[0], 0});
        for(int i=1; i<N; i++)
        {
            while(!PQ.empty()){
                pair<int,int>  P = PQ.top();
                if(P.second >= i-k){
                    dp[i] = max(dp[i], P.first + nums[i]);
                    break;                    
                } else 
                    PQ.pop();
            }
            PQ.push({dp[i], i});
        }
        return dp[N-1];
    }
};