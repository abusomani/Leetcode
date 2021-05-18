class Solution {
private:
    char zero = '0';
public:
    vector<string> cases(string s) {
        if (s.size() == 1) 
            return {s};
        if (s.front() == zero) { // 0567789
            if (s.back() == zero) // 0576570
                return {};
            return {"0." + s.substr(1)}; // 0.234569
        }
        if (s.back() == zero) // 9516150
            return {s};
        int N = s.size();
        vector<string> res{s}; // 945544659
        for (int i = 1; i < N; i++)
            res.push_back(s.substr(0, i) + "." + s.substr(i));
        return res;
    }

    vector<string> ambiguousCoordinates(string S) {
        int N = S.size();
        vector<string> res;
        // Actual string is from 1 to N-2, first and last character is bracket
        for (int i = 2; i < N - 1; i++)
        {
            // for each i, 1 to i-1 and i to end
            for (auto &x : cases(S.substr(1, i - 1)))
                for (auto &y : cases(S.substr(i, N-i-1)))
                    res.push_back("(" + x + ", " + y + ")");
        }
        return res;
    }
};