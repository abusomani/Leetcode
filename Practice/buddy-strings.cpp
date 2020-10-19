class Solution {
public:
    bool buddyStrings(string A, string B) {
        int N = A.size(), M = B.size(), mis = 0, val = 0;
        vector<int> misMatch;
        if(N!=M)
            return false;
        
        for(int i=0; i<N; i++)
            if(A[i] != B[i])
                mis++, misMatch.push_back(i);
        
        int cnt[26] = {0};
        for(auto &s : A) {
            cnt[s-'a']++;
            if(cnt[s-'a'] > 1)val++;
        }
        
        if(mis > 2)
            return false;
        else {
            if(mis == 2) {
                return A[misMatch[0]] == B[misMatch[1]] and A[misMatch[1]] == B[misMatch[0]];
            }
            else 
                return misMatch.empty() and val > 0;
        }
    }
};
class Solution {
public:
    bool buddyStrings(string A, string B) {
        int N = A.size(), M = B.size();
        if(N != M)return false;
        if(A == B) {
            int cnt[26] = {0};
            for(auto &s : A)cnt[s-'a']++;
            for(auto &i : cnt)
                if(i > 1)
                    return true;
            
            return false;
        } else {
            int first = -1, second = -1;
            for(int i=0; i<N; i++) {
                if(A[i] != B[i])
                {
                    if(first == -1)
                        first = i;
                    else if(second == -1)
                        second = i;
                    else
                        return false;
                }
            }
            
            return (first != -1 and second != -1 and A[first] == B[second] and A[second] == B[first]);
        }
    }
};