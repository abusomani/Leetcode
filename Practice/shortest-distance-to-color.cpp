class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<colors.size();i++)
            mp[colors[i]].push_back(i);
        
        vector<int> res;
        for(auto x:queries)
        {
            int idx = x[0];
            int col = x[1];
            if(mp.find(col)==mp.end())
            {
                res.push_back(-1);
                continue;
            }
            
            int pos = lower_bound(mp[col].begin(),mp[col].end(), idx) - mp[col].begin();
            if(pos==0)
                res.push_back(abs(idx-mp[col][pos]));
            else if(pos==mp[col].size())
                res.push_back(abs(idx-mp[col][pos-1]));
            else
                res.push_back(min(abs(idx - mp[col][pos]), abs(idx - mp[col][pos-1])));
        }
        
        return res;
    }
};
/*
[1,1,2,1,3,2,2,3,3]
[[1,3],[2,2],[6,1]]
[1,2]
[[0,3]]
[2,1,2,2,1]
[[1,1],[4,3],[1,3],[4,2],[2,1]]
*/