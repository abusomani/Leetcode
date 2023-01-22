/*
why (ty-sy)%sx == 0?
since
sy will translate to ty only by (sx+sy), if they translate then(sx, sy+k*sx) = ty for some k
sy+k*sx = ty => (ty-sy) / sx = k.
Since sx,sy,tx,ty are all integer, then k has to be a integer which means, 
there must be a integer k that help us to reach ty. Which makes reminder to be 0
Hence
(ty-sy) % sx == 0
*/
class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        while (tx > sx and ty > sy)
        {
            if (tx > ty)
                tx %= ty;
            else
                ty %= tx;
        }

        return (sx == tx and sy <= ty and (ty - sy) % sx == 0) or (sy == ty and sx <= tx and (tx - sx) % sy == 0);
    }
};