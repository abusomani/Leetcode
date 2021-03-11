class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int N = pid.size();
        unordered_map<int, vector<int>> Graph;
        
        for(int i=0; i<N; i++)
        {
            Graph[ppid[i]].push_back(pid[i]); // a node can have multiple children
            if(!Graph.count(pid[i])) // also add this node to the graph
                Graph[pid[i]] = {};
        }
        if(!Graph.count(kill)) // no process exists
            return {};
        
        vector<int> toBeKilled;
        queue<int> Q;
        Q.push(kill);
        while(!Q.empty()){
            int sz = Q.size();
            while(sz--){
                int node = Q.front(); Q.pop();
                toBeKilled.push_back(node);
                for(auto children: Graph[node])
                    Q.push(children);
            }
        }
        return toBeKilled;
    }
};