class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for(auto i : asteroids) {
            if(i > 0) // going right
                s.push_back(i);
            else {
                while(!s.empty() and s.back() > 0 and s.back() < abs(i))s.pop_back();
                if(s.empty() or s.back() < 0)s.push_back(i);
                else if(s.back() == -i)s.pop_back();
            }
        }
        return s;
    }
};