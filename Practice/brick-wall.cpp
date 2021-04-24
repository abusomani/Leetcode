class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> Mp;
        for(auto row: wall) {
            int sm = 0;
            for(auto c : row)
                sm += c, Mp[sm]++;
            // do not consider last edge
            Mp[sm] = 0;
        }
        int mx = 0;
        for(auto p : Mp)
            mx = max(mx, p.second);
        return wall.size() - mx;
    }
};