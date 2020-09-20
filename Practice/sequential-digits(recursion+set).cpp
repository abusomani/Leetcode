class Solution {
private:
    set<int> res;
public:
    void dfs(int low, int high, string num) {
        if(!num.empty()) {
            int val = stoi(num);
            if(val >= low and val <= high)
                res.insert(val);
            char ch = num.back();
            ch++;
            if(ch <= '9')
                dfs(low, high, num + ch);
        }
        else
        {
            for(char i='1'; i<='9'; i++)
                dfs(low, high, num + i);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        dfs(low, high, "");
        return vector<int>(res.begin(), res.end());
    }
};