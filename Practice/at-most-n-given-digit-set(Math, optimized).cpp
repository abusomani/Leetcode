class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& V, int n) {
        int ans = 0;
        string num = to_string(n);
        int N = num.size();
        // doesnt matter for length less than equal to N, all digits are valid
        for(int i=1; i<N; i++)
            ans += pow(V.size(), i);
        
        bool searchNextDigit = true;
        for(int i=0; i<N and searchNextDigit; i++) {
            char max_dig = num[i];
            searchNextDigit = false;
            
            for(auto &dig: V) {
                if(dig[0] < max_dig) // all rest values are valid
                    ans += pow(V.size(), N-i-1);
                else if(dig[0] == max_dig) {
                    searchNextDigit = true; // have to search next
                    if(i == N-1) // this is also one number
                        ans++;
                    break;
                }
            }
        }
        return ans;
    }
};