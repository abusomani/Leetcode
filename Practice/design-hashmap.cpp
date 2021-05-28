int BUCKET_SIZE = 100005;
class MyHashMap {
private:
    vector<list<pair<int,int>>> bucket;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        bucket.resize(BUCKET_SIZE);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key % BUCKET_SIZE;
        for(auto &p: bucket[idx]){
            if(p.first == key){
                p.second = value;
                return;
            }
        }
        bucket[idx].push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key % BUCKET_SIZE;
        for(auto &p: bucket[idx]){
            if(p.first == key){
                return p.second;
            }
        }
        return -1;
        
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = key % BUCKET_SIZE;
        for(auto it = bucket[idx].begin(); it != bucket[idx].end(); it++){
            auto p = *it;
            if(p.first == key){
                bucket[idx].erase(it);
                return;
            }
        }
    }
};
