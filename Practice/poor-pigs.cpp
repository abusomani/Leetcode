/**
 * Given N sources with exactly one of them sending bad signal. 
 * You are given x receivers to detect which source is sending bad signal. 
 * A receiver can be configured to pick up signals from any number of specified sources. 
 * The bad signal will permanently damage a receiver within minutesToDie minutes after received. 
 * Find the minimum x if given minutesToTest minutes to test.
 * 
 * 
 * Number of tests allowed T = (int)(minutesToTest/minutesToDie) because of the "cool down" restriction.
 * 
 * Then the problem is translated equivalently to:
 * 
 * How many states can we generate with x pigs and T tests to cover N scenarios?
 * 
 * The number of states is exactly (T+1)^x and here is why. 
 * For each pig during T tests, it has exactly T+1 states: dies at some test#i (1<=i<=T) or still alive eventually. 
 * For x pigs, obviously the maximum possible number of states we could have is (T+1)^x since each pig's well-being solely depends on whether it ever fed on poison bucket and nothing to do with other pigs. 
 * 
 * More detailed : https://leetcode.com/problems/poor-pigs/discuss/94307/Turn-dynamic-programming-into-mathematical-formula
 * 
 **/
class Solution {
public:
    int poorPigs(int N, int minutesToDie, int minutesToTest) {
        if(N == 1)
            return 0;
        int T = minutesToTest / minutesToDie;
        int l = 1 , r = N, ans = -1;
        while(l<= r){
            int mid = l + ((r-l)>>1);
            if(mid * log(T+1) >= log(N))
                ans = mid , r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
    int poorPigs(int N, int minutesToDie, int minutesToTest) {
        return ceil(log(N) / log(minutesToTest / minutesToDie + 1));
    }
};