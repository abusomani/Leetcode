/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution
{
public:
    int findCelebrity(int n, int celeb = 0)
    {
        for (int i = 1; i < n; i++)
            if (knows(celeb, i))
                celeb = i;
        // after previous loop we have our celeb candidate, now verify
        for (int i = 0; i < n; i++)
            if (i != celeb and (!knows(i, celeb) or knows(celeb, i))) //if celeb knows i or i does not know celeb
                return -1;
        return celeb;
    }
};