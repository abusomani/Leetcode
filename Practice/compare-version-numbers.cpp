class Solution {
public:
    int compareVersion(string A, string B) {
        int N = A.size(), M = B.size() , i = 0, j = 0;
        long n1 = 0, n2 = 0;
        while(i < N or j < M)
        {
            while(i < N and A[i] != '.')
                n1 = n1 * 10 + (A[i++] - '0');
            while(j < M and B[j] != '.')
                n2 = n2 * 10 + (B[j++] - '0');
            if(n1 < n2)return -1;
            else if(n1 > n2)return 1;
            n1 = 0;
            n2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};