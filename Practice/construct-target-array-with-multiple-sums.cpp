class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1)
            return target[0] == 1;
        
        priority_queue<int> pq;
        long totalSum = 0;
        for(auto num: target)
            totalSum += num, pq.push(num);
        while (pq.top() > 1) {
            int largest = pq.top(); 
            pq.pop();
            int rest = totalSum - largest;
            if(rest == 1)
                return true;
            int x = largest % rest;
            if (x == 0 or x == largest) return false;
            pq.push(x);
            totalSum = totalSum - largest + x;
        }
        
        return true; 
    }
};