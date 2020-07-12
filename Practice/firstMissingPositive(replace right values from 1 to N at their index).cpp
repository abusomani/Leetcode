class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int N = A.size();
        for(int i=0;i<N;i++){
           while(A[i] > 0 and A[i] <= N and A[A[i] - 1] != A[i])
               swap(A[i], A[A[i]-1]);
        }
        
        for(int i=0;i<N;i++)
            if(A[i] != (i+1))return (i+1);
        
        return N+1;
    }
};