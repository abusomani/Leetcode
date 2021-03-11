class Solution {
private:
    bool isPalin(string s){
        int N = s.size(), l = 0 , r = N-1;
        while(l <= r and s[l] == s[r])
            l++, r--;
        return (l >= r);
    }
public:
    int removePalindromeSub(string s) {
        if(s.empty())
            return 0;
        if(isPalin(s))
            return 1;
        unordered_set<char> St(s.begin(), s.end());
        return (int)St.size();
    }
};