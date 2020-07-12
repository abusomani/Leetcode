/*
Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"

Naive:

    for (int[] move : shift) {
      int direction = move[0];
      int amount = move[1] % len;
      if (direction == 0) {
        // Move necessary amount of characters from front to end
        string = string.substring(amount) + string.substring(0, amount);
      } else {
        // Move necessary amount of characters from end to front
        string = string.substring(len - amount) + string.substring(0, len - amount);
      }
    }
*/
class Solution
{
public:
    void populate(string s, vector<string> &V)
    {
        string str = "";
        for (auto c : s)
        {
            str += c;
            V[str.size()] = str;
        }
    }
    string stringShift(string s, vector<vector<int>> &shifts)
    {
        int N = s.size();
        vector<string> left(N + 1, ""), right(N + 1, "");
        populate(s, right); // [0,1,2,...i]
        reverse(s.begin(), s.end());
        populate(s, left); // [x,x+1,....size-1]
        for (string &s : left)
            reverse(s.begin(), s.end()); // because its [x,x+1,...size-1]

        int sum = 0;
        for (auto shift : shifts)
        {
            sum += (shift[0] == 0) ? -shift[1] : shift[1];
            sum = (N + sum) % N;
            cout << left[abs(sum)] + right[N - abs(sum)] << endl;
        }

        return left[abs(sum)] + right[N - abs(sum)];
    }
};