class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int N = security.size();
        vector<int> nonIncreasing(N, 1), nonDecreasing(N, 1); // number of elements with non-increasing or non-decreasing
        for(int i=1; i<N; i++)
            if(security[i] <= security[i-1])
                nonIncreasing[i] = 1 + nonIncreasing[i-1];
        for(int i=N-2; i>=0; i--)
            if(security[i] <= security[i+1])
                nonDecreasing[i] = 1 + nonDecreasing[i+1];
        vector<int> res;
        for(int i=0; i<N; i++){
            if(i < time)continue;
            if(nonIncreasing[i] >= time+1 and nonDecreasing[i] >= time+1)
                res.push_back(i);
        }
        return res;
    }
};