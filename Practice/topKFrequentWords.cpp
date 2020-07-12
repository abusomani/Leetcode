class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> Mp;
        for(auto word : words)
            Mp[word]++;
        
        priority_queue<pair<int,string>> PQ; // default is max heap, if count is -1, it will be min heap
        for(auto i : Mp)
        {
            PQ.emplace(make_pair(-i.second, i.first));
            if(PQ.size() > k)
                PQ.pop();
        }
        int N = PQ.size();
        vector<string> res(N);
        
        for(int i=N-1;i>=0;i--){
            res[i] = PQ.top().second;
            PQ.pop();
        }
        
        return res;
    }
};