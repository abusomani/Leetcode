/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

class MovingAverage{
private:
    deque<int> Dq;
    double res = 0;
    int N;
public:
    MovingAverage(int size){
        N = size;
    }
    double next(int val) {
        Dq.push_back(val);
        res += val;
        if(Dq.size() > N) {
            res -= Dq.front();
            Dq.pop_front();
        }
        return res / min((int)Dq.size(), N);
    }
};