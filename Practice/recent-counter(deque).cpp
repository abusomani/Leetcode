class RecentCounter {
private:
    deque<int> Dq;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        Dq.push_back(t);
        while(Dq.front() < t - 3000)
            Dq.pop_front();
        return Dq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */