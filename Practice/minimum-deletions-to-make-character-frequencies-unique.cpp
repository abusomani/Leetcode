class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        for(auto c: s)cnt[c-'a']++;
        unordered_set<int> St;
        int res = 0;
        for(int i=0; i<26; i++){
            int freq = cnt[i];
            while(freq > 0 and St.count(freq)){
                freq--;
                res++;
            }
            if(freq)
                St.insert(freq);
        }
        return res;
    }
};