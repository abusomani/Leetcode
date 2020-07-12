class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=1;i<=n;i++)
            res.push_back(i % 3 == 0 ? i % 5 == 0 ? "FizzBuzz" : "Fizz" : i% 5 == 0 ? "Buzz" : to_string(i));
            
        return res;
    }
};