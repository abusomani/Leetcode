class Solution {
public:
    int sumOfDigits(int n) {
        int ans = 0;
        while(n) {
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
    int productOfDigits(int n) {
        int ans = 1;
        while(n) {
            ans *= n%10;
            n /= 10;
            if(ans == 0)return 0;
        }
        return ans;
    }
    int subtractProductAndSum(int n) {
        return productOfDigits(n) - sumOfDigits(n);
    }
};