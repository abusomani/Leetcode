int MAX = 5e6+5;
class Solution {
private:
    vector<int> primes;
    void mark(long n){
        for(long i=n*n; i<primes.size(); i+= n)
            primes[i] = 0;
    }
    void init(int n){
        primes.resize(min(n, MAX), 1);
        primes[0] = primes[1] = 0;
        mark(2);
        for(int i=3; i<= sqrt(primes.size()); i+=2)
            if(primes[i])
                mark(i);
            
    }
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        init(n);
        return accumulate(primes.begin(), primes.end(), 0);
    }
};