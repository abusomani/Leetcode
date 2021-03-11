class Solution {
private:
    vector<char> vowels = {'a','e','i','o','u'};
public:
    int dfs(int idx, int N, int ctr) {
        if(ctr == N)
            return 1;
        int ans = 0;
        for(int i=idx; i< vowels.size(); i++) {
            ctr++;
            ans += dfs(i, N, ctr);
            ctr--;
        }
        return ans;
    }
    int countVowelStrings(int n) {
        return dfs(0, n, 0);
    }
};