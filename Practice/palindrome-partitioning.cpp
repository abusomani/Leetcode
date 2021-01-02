// O(N*N* 2^N), linear time for checking palindrome and 2^N for dfs.
// Everytime we have an option to bifurcate into a tree.
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
        if(last_idx == 0)
        {
            reverse(path.begin(), path.end());
            res.push_back(path);
        }
        else {
            for(int len=1; len<= last_idx; len++) {
                string sub = s.substr(last_idx - len, len);
                if(isPalin(sub))
                {
                    path.push_back(sub);
                    dfs(path, last_idx-len, s);
                    path.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> P;
        dfs(P, s.size(), s);
        return res;
    }
};