class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> PQ;
        for(auto &num : nums)PQ.push(num);
        while(--k)
            PQ.pop();
        return PQ.top();
    }
};

class Solution1
{
public:
    struct compare
    {
        bool operator()(int &a, int &b)
        {
            return a > b;
        }
    };
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, compare> PQ;
        for (int i = 0; i < k; i++)
            PQ.push(nums[i]);
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] >= PQ.top())
            {
                PQ.pop();
                PQ.push(nums[i]);
            }
        }
        return PQ.top();
    }
};

class Solution2
{
public:
    struct compare
    {
        bool operator()(int &a, int &b)
        {
            return a > b;
        }
    };
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, compare> PQ;
        for (auto &num : nums)
        {
            PQ.push(num);
            if (PQ.size() > k)
                PQ.pop();
        }
        return PQ.top();
    }
};

class Solution3
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int N = nums.size(), l = 0, r = N - 1;
        k = N - k;
        while (l <= r)
        {
            int mid = helper(nums, l, r);
            if (mid == k)
                return nums[mid];
            else if (mid < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    int helper(vector<int> &nums, int l, int r)
    {
        int i = l; // where to swap from.
        // l is reference
        for (int j = l + 1; j <= r; j++)
        {
            if (nums[j] < nums[l])
                swap(nums[j], nums[++i]);
        }
        swap(nums[l], nums[i]);
        return i;
    }
};