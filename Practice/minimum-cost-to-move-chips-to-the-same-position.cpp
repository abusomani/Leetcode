class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ans = INT_MAX, N = position.size();
        unordered_map<int,int> dp;
        for(int i=0; i<N; i++) {
            int valid = position[i], cost = 0;
            if(dp.count(valid))
                continue;
            
            for(int j=0; j<N; j++) {
                int diff = abs(valid - position[j]);
                if(diff&1)
                    cost++;
            }
            dp[valid] = cost;
            ans = min(ans, cost);
        }
        return ans;
    }
    // Move all chips to position 0 and all chips to positon 1
    int minCostToMoveChips(vector<int> &position)
    {
        int even = 0, odd = 0;
        for (auto &p : position)
        {
            if (p & 1)
                odd++;
            else
                even++;
        }
        return min(odd, even);
    }
};