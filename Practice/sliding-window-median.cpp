/*
Time complexity: O((n-k)* 6 logk) ≈O(nlogk).

At worst, there are three set insertions and three set deletions from the start or end. Each of these takes about O(\log k)O(logk) time.
Finding the mean takes constant O(1)time since the start or ends of sets are directly accessible.
Each of these steps takes place about (n-k) times (the number of sliding window instances).
Space complexity: O(k) extra linear space to hold contents of the window.
*/
typedef long long ll;
class Solution
{
private:
    multiset<ll> large, small; // large for larger half, small for smaller half
    void balance()
    {
        if (large.size() < small.size()) // ensures large's size >= small
        {
            large.insert(*small.rbegin()); // as large will have larger set of elements
            small.erase(--small.end());
        }
    }
    void remove(ll num)
    {
        if (small.count(num))
        {
            small.insert(*large.begin());
            large.erase(large.begin());
            small.erase(small.find(num));
            large.insert(num);
        }
        if (large.count(num))
            large.erase(large.find(num));
        balance();
    }
    void add(ll num)
    {
        large.insert(num);            // directly add to large
        small.insert(*large.begin()); // small will have smaller half, hence begin()
        large.erase(large.begin());   // erase from large
        balance();
    }
    double getMedian()
    {
        return (large.size() > small.size()) ? (double)*large.begin() : (*large.begin() + *small.rbegin()) / 2.0;
    }

public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> res;
        int N = nums.size();
        if (N == 0)
            return res;
        for (int i = 0; i < k; i++)
            add(nums[i]);
        for (int i = k; i < N; i++)
        {
            res.push_back(getMedian());
            remove(nums[i - k]);
            add(nums[i]);
        }
        res.push_back(getMedian());
        return res;
    }
};