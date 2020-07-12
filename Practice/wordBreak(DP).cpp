class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto s : wordDict)dict.insert(s);
        
        return wordBreak(s,dict);
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false); // string ending till ith position
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++) // lengths
        {
            for(int j=i-1;j>=0;j--) // string starting from index j
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};