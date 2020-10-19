class Solution {
public:
    int getValue(vector<int> &A, vector<int>&B, int a, bool useA) {
        int a_ans = 0, N = A.size();
        for(int i=0;i<N; i++) {
            if(useA) {
                if(A[i] == a)continue;
                if(B[i] == a)a_ans++;
                else
                {
                    a_ans = INT_MAX;
                    break;
                }
            } else {
                if(B[i] == a)continue;
                if(A[i] == a)a_ans++;
                else
                {
                    a_ans = INT_MAX;
                    break;
                }
            }
        }
        return a_ans;
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a = A[0], b = B[0], a_ans = 0, b_ans = 0;
        a_ans = getValue(A, B, a, true);
        a_ans = min(a_ans, getValue(A, B, b, true));
        b_ans = getValue(A, B, a, false);
        b_ans = min(b_ans, getValue(A, B, b, false));
        return (a_ans == INT_MAX and b_ans == INT_MAX) ? -1 : min(a_ans, b_ans);
    }
};