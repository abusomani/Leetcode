class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> PQ;
        for(auto stick: sticks)PQ.push(stick);
        int res = 0;
        while(PQ.size() > 1){
            int A = PQ.top(); PQ.pop();
            int B = PQ.top(); PQ.pop();
            res += A + B;
            PQ.push(A+B);
        }
        return res;
    }
};