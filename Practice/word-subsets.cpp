class Solution {
private:
    vector<int> toVector(string a){
        vector<int> res(26, 0);
        for(auto &i: a)
            res[i-'a']++;
        return res;
    }
    vector<int> combine(vector<int> &res, vector<int> &A){
        for(int i=0; i<26; i++)
            res[i] = max(res[i], A[i]);
        return res;
    }
    bool isSubset(vector<int> A, vector<int> B){
        int N = A.size();
        for(int i=0; i<N; i++)
            if(B[i]>A[i])
                return false;
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> universal;
        vector<int> combined(26, 0);
        for(auto &s: B)
        {
            vector<int> cnt = toVector(s);
            combined = combine(combined, cnt);
        }
        for(auto &i: A)
        {
            vector<int> cnt = toVector(i);
            if(isSubset(cnt, combined))
                universal.push_back(i);
        }
        return universal;
    }
};