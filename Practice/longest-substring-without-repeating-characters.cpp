class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0 , N = s.size(), start = 0, end = 0, counter = 0;
        unordered_map<char,int> Mp;
        while(end < N){
            if(Mp[s[end++]]++ > 0)
                counter = 1;
            while(counter > 0) {
                if(Mp[s[start++]]-- > 1)
                    counter = 0;
            }
            ans = max(ans, end-start);
        }
        return ans;
    }
};