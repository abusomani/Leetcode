class Solution {
public:
    unordered_map<int,int> nextGreaterElement(vector<int> A) {
        stack<int> St;
        int N = A.size();
        unordered_map<int,int> Mp;
        for(int i=0;i<N;i++) {
            while(!St.empty() and A[i] > St.top())
            {
                Mp[St.top()] = A[i];
                St.pop();
            }
            St.push(A[i]);
        }
        
        while(!St.empty())
        {
            Mp[St.top()] = -1;
            St.pop();
        }
        return Mp;
    }
    vector<int> nextGreaterElement(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> BMp = nextGreaterElement(B);
        vector<int> res;
        for(auto i : A)
            res.push_back((BMp.find(i) != BMp.end() ? BMp[i] : -1));
        
        return res;
    }
};