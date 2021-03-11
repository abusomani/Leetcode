class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        for(int i=0; i<n; i++) {
            int val = (n-i-1)*26;
            if(k <= val)
                res += "a";
            else
                res += ('a' + (k - val - 1));
            k -= (res.back() - 'a' + 1);
        }
        return res;
    }
};