class Solution {
private:
    int diff(vector<int> &A, vector<int> &B){
        for(int i=1; i<B.size(); i++)
            if(A[i] != B[i])
                return A[i];
        return -1;
    }
public:
    int missingNumber(vector<int>& V) {
        int a = V[V.size()-1] - V[V.size()-2], b = V[1]-V[0];
        if(a == 0 or b == 0)
            return V[0];
        vector<int> A, B;        
        int num;
        for(int i=0; i<=V.size(); i++){
            if(i == 0)
                num = V[i];
            else
                num += a;
            A.push_back(num);
        }
        for(int i=0; i<=V.size(); i++){
            if(i == 0)
                num = V[i];
            else
                num += b;
            B.push_back(num);
        }
        return (A.back() == V.back() and A.front() == V.front()) ? diff(A, V) : diff(B, V);
    }
};