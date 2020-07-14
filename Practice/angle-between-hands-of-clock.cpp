class Solution
{
public:
    /*
    180 mins => 90 degrees of hour hand
    1 min => 0.5 degrees of hour hand
    */
    double angleClock(int H, int M)
    {
        double angleMinutes = M * 6;
        double absoluteAngleHour = H * 30 + (double)M / 2;
        double rightSideAngle = abs(absoluteAngleHour - angleMinutes);
        return min(rightSideAngle, 360 - rightSideAngle);
    }
};