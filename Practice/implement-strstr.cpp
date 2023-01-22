class Solution {
private:
    vector<int> KMP(string s){
        int N = s.size(), j = 0;
        vector<int> lps(N, 0);
        for(int i=1; i<N; i++)
        {
            j = lps[i-1];
            while(j > 0 and s[i] != s[j])
                j = lps[j-1];
            if(s[i] == s[j])j++;
            lps[i] = j;
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        vector<int> lps = KMP(needle);
        int N = haystack.size();
        for(int i=0,j=0; i<N; i++){
            while(j > 0 and haystack[i] != needle[j])
                j = lps[j-1];
            if(haystack[i] == needle[j])
                j++;
            if(j == needle.size())
                return (i-j+1);
        }
        return -1;
    }
};