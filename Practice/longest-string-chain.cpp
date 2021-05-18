class Solution {
private:
    vector<string> possibleStrings(string s, unordered_set<string> &St){
        vector<string> p;
        for(int i=0; i<s.size(); i++){
            string tmp = s.substr(0,i) + s.substr(i+1);
            if(St.count(tmp))
                p.push_back(tmp);
        }
        return p;
    }
public:
    int longestStrChain(vector<string>& words) {
        int maxLen = 0, res = 0;
        map<string, int> dp;
        unordered_map<int, unordered_set<string>> W;
        for(auto word: words)
            dp[word] = 1, maxLen = max(maxLen, (int)word.size()), W[(int)word.size()].insert(word);
        
        for(int len=2; len <= maxLen; len++){
            for(auto word: W[len]){
                for(auto small : possibleStrings(word, W[len-1])){
                    dp[word] = max(dp[word], 1 + dp[small]);
                }
            }
        }
        for(auto p : dp)
            res = max(res, p.second);
        return res;
    }
};