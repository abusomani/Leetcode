class HitCounter
{
private:
    vector<int> times, hits;

public:
    /** Initialize your data structure here. */
    HitCounter()
    {
        times.resize(300); // past 300 seconds
        hits.resize(300);
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp)
    {
        int idx = timestamp % 300;
        if (times[idx] != timestamp)
        { // also handles 301,302, and so on
            times[idx] = timestamp;
            hits[idx] = 1; // reset or start the counter both ways
        }
        else
            ++hits[idx];
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp)
    {
        int ans = 0;
        for (int i = 0; i < 300; i++)
            if (timestamp - times[i] < 300) // past 300 seconds
                ans += hits[i];

        return ans;
    }
};
