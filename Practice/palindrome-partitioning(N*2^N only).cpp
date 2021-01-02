class Solution {
private:
    bool isPalin(string s) {
        int N = s.size();
        int l = 0 , r = N-1;
        while(l < r) {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    vector<vector<string>> res;
public:
    void dfs(vector<string> path, int last_idx, string &s) {
        if(last_idx == s.size())
            res.push_back(path);
        else {
            for(int len=1; len <= s.size()-last_idx; len++) {
                
                string sub = s.substr(last_idx, len);
                if(isPalin(sub))
                {
                    path.push_back(sub);
                    dfs(path, last_idx+len, s);
                    path.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> P;
        dfs(P, 0, s);
        return res;
    }
};