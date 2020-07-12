class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size(), ans = 0, sm = 0;
        if(N == 0)return 0;
        for(int i=1;i<N;i++){
            sm = max(0, sm += prices[i] - prices[i-1]);
            ans = max(ans, sm);
        }
        
        return ans;
    }
};