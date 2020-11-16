class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans = 0, N = A.size(), i = 1;
        while(i < N) {
            int inc = 0, dec = 0;
            while(i < N and A[i] > A[i-1])
                i++, inc++;
            while(i < N and A[i] < A[i-1])
                i++, dec++;
            
            if(inc > 0 and dec > 0)
                ans = max(ans, inc + dec + 1);
            
            while(i < N and A[i] == A[i-1])i++;
        }
        return ans;
    }
};