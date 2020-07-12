class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> Mp;
        for(auto i : nums)
            Mp[i]++;
        
        priority_queue<pair<int,int>> PQ;
        for(auto i : Mp) {
            PQ.emplace(make_pair(-i.second,i.first));
            if(PQ.size() > k)
                PQ.pop();
        }
        int N = PQ.size();
        vector<int> V(N);
        for(int i=N-1;i>=0;i--)
            V[i] = PQ.top().second, PQ.pop();
        
        return V;
    }
};