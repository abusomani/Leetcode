class Solution {
public:
    int maxPower(string s) {
        int N = s.size(), ans = 0, cnt = 0;
        char ch = '#';
        for(auto &c : s) {
            if(ch != c) {
                ans = max(ans, cnt);
                cnt = 1;
                ch = c;
            } else
                cnt++;
        }
        return max(ans, cnt);
    }
};