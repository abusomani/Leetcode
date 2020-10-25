class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto &a : asteroids) {
            if(res.empty() or res.back() < 0 or a > 0) {
                res.push_back(a);
            } else {
                int stone = a;
                while(!res.empty() and res.back() > 0 and stone < 0) {
                    if(abs(stone) == abs(res.back())) {
                        res.pop_back();
                        stone = 0;
                        break;
                    }
                    else if(abs(stone) < abs(res.back())){
                        stone = 0;
                        break;
                    }
                    else {
                        res.pop_back();
                    }
                }
                if(stone != 0)
                    res.push_back(stone);
            }
        }
        return res;
    }
};