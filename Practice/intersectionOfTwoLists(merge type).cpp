class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>ans;
        int N = A.size(), M = B.size();
        
        for(int i=0,j=0; i<N and j<M; A[i][1] < B[j][1] ? i++:j++) {
            int start = max(A[i][0],B[j][0]);
            int end = min(A[i][1],B[j][1]);
            if(start <= end)
                ans.push_back({start,end});
        }
        
        return ans;
    }
};