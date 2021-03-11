class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> St;
        int N = pushed.size(), i = 0, j = 0;
        while(j < N){
            if(St.empty()){
                if(i >= N)return false;
                else
                    St.push(pushed[i++]);
            } else {
                if(St.top() == popped[j])
                    St.pop(), j++;
                else
                {
                    if(i >= N)return false;
                    else
                        St.push(pushed[i++]);
                }
            }
        }
        return i >= N and j >= N;
    }
};