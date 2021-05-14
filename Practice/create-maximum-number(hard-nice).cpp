class Solution {
private:
    vector<int> maxNumber1D(vector<int> &A, int len){
        vector<int> res(len, 0);
        int N = A.size();
        for(int i=0, j=0; i<N; i++){
            // (N-i) digits left and (len-j) required
            while(j and res[j-1] < A[i] and N-i> len-j)
                j--;
            if(j < len)
                res[j++] = A[i];
        }
        return res;
    }
    auto max(vector<int> A, vector<int> B){
        if(A.size() > B.size())return A;
        else if(A.size() < B.size())return B;
        else{
            for(int i=0; i<A.size(); i++){
                if(A[i] > B[i])return A;
                else if(A[i] < B[i])return B;
            }
            return A;
            
        }
    }
    vector<int> concat(vector<int> &A, vector<int> &B){
        vector<int> res;
        int N = A.size(), M = B.size(), i = 0, j = 0;
        while(i < N and j < M){
            if(A[i] > B[j])
                res.push_back(A[i++]);
            else if(A[i] < B[j])
                res.push_back(B[j++]);
            else{
                // Both are equal, we need to pick the one that is better in the future
                int i1 = i + 1;
                int j1 = j + 1;
                int larger = 0; 
                
                while(i1< N && j1 < M && !larger) {
                    if(A[i1] == B[j1]) {
                        if (A[i1] < A[i]) // worse than current position
                            break;
                        i1++;
                        j1++;
                    }
                    else if (A[i1] > B[j1])
                        larger = -1;
                    else
                        larger = 1;  // nums2 is better to pick 
                }
                
                if (i1 == N)
                    larger = 1;
                else if (j1 == M)
                    larger = -1;
                
                if (larger == -1)
                    res.push_back(A[i++]);
                else 
                    res.push_back(B[j++]);
            }
        }
        while(i < N)
            res.push_back(A[i++]);
        while(j < M)
            res.push_back(B[j++]);
        return res;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res = {};
        for(int len=0; len <= min(k, (int)nums1.size()); len++){
            if(k - len > nums2.size())
                continue;
            auto first = maxNumber1D(nums1, len);
            auto second = maxNumber1D(nums2, k - len);
            res = max(res, concat(first, second));
        }
        return res;
    }
};