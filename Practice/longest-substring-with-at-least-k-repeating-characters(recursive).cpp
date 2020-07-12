/*
1. In the first pass I record counts of every character in a hashmap
2. In the second pass I locate the first character that appear less than k times in the string. 
This character is definitely not included in the result, and that separates the string into two parts.
3. Keep doing this recursively and the maximum of the left/right part is the answer.
*/
//Time Complexity => O(N) There is at most 26 level. If you split the string using char x in the previous level, you won't be able to use it in the current level.
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int N = s.size();
        if (N == 0 or k > N)
            return 0;
        if (k == 0)
            return N;

        vector<int> Mp(256, 0);
        for (auto ch : s)
            Mp[ch]++;
        int mid = 0;
        while (mid < N and Mp[s[mid]] >= k)
            mid++;

        if (mid == N) // entire substring is answer
            return N;

        int left = longestSubstring(s.substr(0, mid), k); // recur for first part
        while (mid < N and Mp[s[mid]] < k)                // this cannt be included in part of the answer
            mid++;

        if (mid == N)
            return left; // last valid

        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
};