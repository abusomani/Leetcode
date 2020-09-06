class Solution {
public:
    void print(vector<int> &A)
    {
        for(auto &i : A)
            cout<<i<<" ";
        cout<<endl;
    }
    vector<int> pancakeSort(vector<int>& A) {
        int N = A.size();
        vector<int> res;
        if(N == 0)
            return res;
        for(int i=N-1; i>=0; i--)
        {
            int mx = INT_MIN, idx = -1;
            for(int j=0; j<=i; j++)
            {
                if(A[j] >= mx)
                    mx = A[j], idx = j;
            }
            res.push_back(idx+1);
            reverse(A.begin(), A.begin()+idx+1);
            res.push_back(i+1);
            reverse(A.begin(), A.begin()+i+1);
        }
        return res;
    }
};