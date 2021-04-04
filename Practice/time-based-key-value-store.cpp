class TimeMap {
private:
    unordered_map<string, vector<pair<string,int>>> Mp;
    string binary_search(vector<pair<string,int>> &V, int time) {
        if(V.empty())
            return "";
        int N = V.size(), l = 0, r = N-1, ans = -1;
        while(l <= r){
            int mid = l + ((r-l)/2);
            if(V[mid].second <= time) {
                ans = mid;
                l = mid+1;
            } else
                r = mid-1;
        }
        return ans == -1 ? "": V[ans].first;
    }
public:
    /** Initialize your data structure here. */
    TimeMap() {
        Mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        Mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        return binary_search(Mp[key], timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */