class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int N = S.size();
        int l = 0, r = N;
        for(auto i : S) 
            res.push_back(i == 'I' ? l++ : r--);
        res.push_back(l);
        return res;
    }
};