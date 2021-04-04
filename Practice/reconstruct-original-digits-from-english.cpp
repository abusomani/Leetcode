class Solution {
public:
    string originalDigits(string s) {
        vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        vector<int> counts(26, 0);
        string result;
        for(auto ch : s){ counts[ch-'a']++;}
        for(int i = 0; i < 10; i++){
            int count = counts[distinct_char[i]-'a'];
            for(int j = 0; j < words[i].size(); j++)
                counts[words[i][j]-'a'] -= count;
            while(count--)
                result += to_string(nums[i]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

class Solution1 {
public:
    string originalDigits(string s) {
       vector<int> a(10, 0);
        vector<int> alpha(128, 0);
        for (char c : s)
            alpha[c]++;
        a[0] = alpha['z'];
        a[2] = alpha['w'];
        a[4] = alpha['u'];
        a[6] = alpha['x'];
        a[8] = alpha['g'];
        a[3] = alpha['h'] - a[8];
        a[5] = alpha['f'] - a[4];
        a[7] = alpha['v'] - a[5];
        a[1] = alpha['o'] - a[0] - a[2] - a[4];
        a[9] = alpha['i'] - a[5] - a[6] - a[8];
        string ans;
        for (int i = 0; i < 10; i++) {
            if (a[i] > 0)
                ans += string(a[i], '0' + i);
        }
        return ans;
    }
};