class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> res;
        while(n)
            res.push_back(n%10), n/= 10;
        reverse(res.begin(), res.end());
        
        int N = res.size(), k , l;
        
        for(k = N-2; k>=0; k--)
            if(res[k] < res[k+1])break;
        
        if(k < 0)return -1;
        
        for(l = N-1; l > k; l--)
            if(res[l] > res[k])break;
        
        swap(res[l], res[k]);
        
        reverse(res.begin()+k+1, res.end());
        
        long long ans = 0;
        for(int i=0;i<N;i++)
            ans = ans*10 + res[i];
        
        return (ans > INT_MAX ? -1 : (int)ans);
        
    }
};