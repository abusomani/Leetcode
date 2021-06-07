class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1, INT_MAX);
        dis[k] = 0;
        // V-1 times
        for(int i=1; i<n; i++){
            // each edge relaxation
            for(auto time: times){
                int x = time[0], y = time[1], w = time[2];
                if(dis[x] != INT_MAX and dis[y] > dis[x] + w){
                    dis[y] = dis[x] + w;
                }
            }
        }
        int maxwait = 0;
        for (int i = 1; i <= n ; i++)
            maxwait = max(maxwait, dis[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};