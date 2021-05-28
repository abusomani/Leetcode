class Solution {
private:
    bool canMatch(string src, string pattern){
        assert(src.size() == pattern.size());
        unordered_map<char,char> Mp, Np;
        for(int i=0; i<src.size(); i++){
            if(Mp.count(src[i]) and Mp[src[i]] != pattern[i])return false;
            if(Np.count(pattern[i]) and Np[pattern[i]] != src[i])return false;
            Np[pattern[i]] = src[i];
            Mp[src[i]] = pattern[i];
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto word: words)
            if(canMatch(word, pattern))
                res.push_back(word);
        return res;
    }
};