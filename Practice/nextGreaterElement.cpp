class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int N = T.size();
        vector<int> ans (N, 0);
        stack<int> St;
        for(int i=0;i<N;i++){
            while(!St.empty() and T[i] > T[St.top()])
            {
                ans[St.top()] = (i-St.top());
                St.pop();
            }
            St.push(i);
        }
        
        return ans;
    }
};