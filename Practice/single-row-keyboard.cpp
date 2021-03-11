class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> cnt(26, 0);
        for(int i=0; i<26; i++)
            cnt[keyboard[i]-'a'] = i;
        int res = 0;
        char start = keyboard[0];
        for(auto &c: word)
            res += abs(cnt[c-'a'] - cnt[start-'a']), start = c;
        return res;
    }
};