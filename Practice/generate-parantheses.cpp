class Solution {
private:
    vector<string> res;
    void dfs(string s, int N, int open, int closed){
        if(s.size() >= 2*N)
        {
            if(open == closed)
                res.push_back(s);
            return;
        }
        s += '(';
        dfs(s, N, open+1, closed);
        s.pop_back();
        if(closed < open)
        {
            s += ')';
            dfs(s, N, open, closed+1);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int N) {
        dfs("", N, 0, 0);
        return res;
    }
};