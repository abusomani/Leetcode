class FreqStack {
private:
    unordered_map<int,int> Frequency;
    unordered_map<int, stack<int>> Buckets;
    int maxFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        Frequency[x]++;
        int f = Frequency[x];
        maxFreq = max(maxFreq, f);
        Buckets[f].push(x);
    }
    
    int pop() {
        int x = Buckets[maxFreq].top();
        Frequency[x]--;
        Buckets[maxFreq].pop();
        if(Buckets[maxFreq].size() == 0)
            maxFreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */