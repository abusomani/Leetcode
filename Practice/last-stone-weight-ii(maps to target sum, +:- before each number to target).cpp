/*
Most of the time, coming up with a solution depends on your intuition (that can be trained by solving lots of problems and recognizing similar problems).

In this case, you smash two stones and the remainder needs to be reused.
Imagining the process: Smash. Pick a new stone with the free hand. Repeat.
Picking the new stone with either your left or right hand already assigns each stone to either left or right, i.e., separates the stones into two sets.

You want to choose stones, such that in the end, you don't have anything left in your hands(or as few as possible).
How to decide whether a split into the two sets was good? Since you can just leave the remainder in the hand and continue smashing, it stays in the same set. Meaning the complete weight is used for one set. The difference between the sets is exactly what remains.

At first glance, it seems like the worst case complexity would be O(2^n), where each iteration doubles the size of set. But this is not true, because the range of possible sums is [-30 * 100, 30 * 100]. Therefore, the maximum size of set is 6000. So the worst complexity is O(6000N) = O(N).
*/
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        unordered_set<int> stoneLeft;
        for (auto stone : stones)
        {
            if (stoneLeft.empty())
            {
                stoneLeft.insert(stone);
                stoneLeft.insert(-stone);
            }
            else
            {
                unordered_set<int> tmp;
                for (auto i : stoneLeft)
                {
                    tmp.insert(i + stone);
                    tmp.insert(i - stone);
                }
                stoneLeft = tmp;
            }
        }

        int result = INT_MAX;
        for (auto i : stoneLeft)
            if (i >= 0)
                result = min(result, i);

        return result;
    }
};