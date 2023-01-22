class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, -1);
        for(int i=0; i< s.size(); i++){
            if(cnt[s[i]-'a'] == -1)
                cnt[s[i]-'a'] = i;
            else
                cnt[s[i]-'a'] = INT_MAX;
        }
        int res = INT_MAX;
        for(auto &i: cnt)
            if(i != -1)
                res = min(res, i);
        return res == INT_MAX ? -1 : res;
    }
};