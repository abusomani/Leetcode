class Solution {
private:
    unordered_set<string> res;
    vector<string> digits = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(string D, int idx, string curr){
        if(idx == D.size())
            res.insert(curr);
        else {
            for(auto c: digits[D[idx]-'0'])
            {
                curr += c;
                dfs(D, idx+1, curr);
                curr.pop_back();
            }
        }
            
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        
        dfs(digits, 0, "");
        vector<string> V;
        for(auto s: res)
            V.push_back(s);
        return V;
    }
};