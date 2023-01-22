/*
    Moore's voting states, 
    That take bracket of K elements with their frequencies 
    Now start decreasing their count by 1 and do following:
        1. If count becomes 0, then erase this number from bracket
        2. Else move to next number

    After this is done till last element, whatever left are candidates for being majority element.
*/
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        return findMajority(nums, 3);
    }
    vector<int> findMajority(vector<int> &nums, int k)
    {
        unordered_map<int, int> Mp;
        for (int i = 0; i < nums.size(); i++)
        {
            Mp[nums[i]]++;
            if (Mp.size() == k) // whenever there are k numbers, start eliminating candidates
            {
                for (auto it = Mp.begin(); it != Mp.end();)
                {
                    it->second--;
                    if (it->second == 0)
                        it = Mp.erase(it); // Trickiest part, erase(iterator) returns the iterator of next valid element
                    else
                        it++;
                }
            }
        }
        for (auto &it : Mp) // the numbers present are the candidates, make their count 0
            it.second = 0;

        for (auto &num : nums)
            if (Mp.count(num))
                Mp[num]++;

        vector<int> res;
        for (auto &it : Mp)
            if (it.second > nums.size() / k) // if count  > (n/k) then its a majority element
                res.push_back(it.first);

        return res;
    }
};