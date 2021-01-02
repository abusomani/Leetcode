class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int,int> AB, CD;
        for(auto &a : A)
            for(auto &b: B)
                AB[a+b]++;
        for(auto &c : C)
            for(auto &d: D)
                CD[c+d]++;
        for(auto &i: AB)
            if(CD.count(-i.first))
                ans += i.second * CD[-i.first];
        
        return ans;
    }
};