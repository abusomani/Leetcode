/*
[0,3,1,4,5,2,1,5,10,6]
3
6
i:(0) >>> left:(-1), right:(-1), res:(0)
i:(1) >>> left:(-1), right:(1), res:(2)
i:(2) >>> left:(-1), right:(1), res:(4)
i:(3) >>> left:(-1), right:(3), res:(8)
i:(4) >>> left:(-1), right:(4), res:(13)
i:(5) >>> left:(-1), right:(4), res:(18)
i:(6) >>> left:(-1), right:(4), res:(23)
i:(7) >>> left:(-1), right:(7), res:(31)
i:(8) >>> left:(8), right:(8), res:(31)
*/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int result=0, left=-1, right=-1;
        for (int i=0; i<A.size(); i++) {
            if (A[i]>R) left=i;
            if (A[i]>=L) right=i;
            result+=right-left;
        }
        return result;
    }
};