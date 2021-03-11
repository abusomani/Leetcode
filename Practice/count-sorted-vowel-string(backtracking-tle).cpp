class Solution {
private:
    vector<char> vowels = {'a','e','i','o','u'};
public:
    int dfs(int idx, int N, string s) {
        if(s.size() == N)
            return 1;
        int ans = 0;
        for(int i=idx; i< vowels.size(); i++) {
            s += vowels[i];
            ans += dfs(i, N, s);
            s.pop_back();
        }
        return ans;
    }
    int countVowelStrings(int n) {
        return dfs(0, n, "");
    }
};