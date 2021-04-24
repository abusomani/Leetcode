class Solution {
private:
    int len = 0;
    bool allUnique(string s){
        unordered_set<char> St(s.begin(), s.end());
        return St.size() == s.size();
    }
    void dfs(string curr, int idx, vector<string> &U){
        if(!allUnique(curr))
            return;
        len = max(len, (int)curr.size());
        for(int i=idx; i<U.size(); i++)
            dfs(curr + U[i], i+1, U);
    }
public:
    int maxLength(vector<string>& arr) {
        vector<string> U;
        for(auto s: arr)
            if(allUnique(s))
                U.push_back(s);
        dfs("", 0 , U);
        return len;
    }
};