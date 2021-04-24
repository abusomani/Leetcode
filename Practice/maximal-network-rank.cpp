class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> In(n, 0);
        set<pair<int,int>> St;
        for(auto road : roads){
            In[road[0]]++;
            In[road[1]]++;
            St.insert({road[0], road[1]});
        }
        int res = 0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                res = max(res, In[i]+ In[j] - (St.count({i,j}) || St.count({j,i})));
        return res;
        
    }
};