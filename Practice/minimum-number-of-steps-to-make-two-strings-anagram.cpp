class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {0};
        for(auto &c : s)
            cnt[c-'a']++;
        int ans = 0;
        for(auto &c : t)
            if(cnt[c-'a'])
                cnt[c-'a']--;
        for(int i=0; i<26; i++)
            ans += abs(cnt[i]);
        return ans;
    }
};