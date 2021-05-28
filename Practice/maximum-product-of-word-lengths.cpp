class Solution {
private:
    bool intersect(unordered_set<char> &St, unordered_set<char> &Bt){
        for(auto c : St)
            if(Bt.count(c))
                return true;
        
        return false;
    }
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<pair<unordered_set<char>, int>> V;
        for(auto w: words)
            V.push_back({unordered_set<char>(w.begin(), w.end()), (int)w.size()});
        
        for(int i=0; i<V.size(); i++)
            for(int j=0; j<V.size(); j++){
                if(i != j and !intersect(V[i].first, V[j].first))
                    res = max(res, V[i].second * V[j].second);
            }
        return res;
    }
};