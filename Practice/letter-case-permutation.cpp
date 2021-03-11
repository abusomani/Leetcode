class Solution {
private:
    vector<string> res;
    void dfs(string S, int idx=0) {
        if(idx == S.size())
            res.push_back(S);
        else {
            if(isdigit(S[idx]))
                dfs(S, idx+1);
            else
            {
                // lower case
                S[idx] = tolower(S[idx]);
                dfs(S, idx+1);
                // upper case
                S[idx] = toupper(S[idx]);
                dfs(S, idx+1);
            }
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        dfs(S);
        return res;
    }
};