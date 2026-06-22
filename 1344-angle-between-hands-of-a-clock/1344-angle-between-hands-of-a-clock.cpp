class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourHandAngle = 30.0 * hour + 0.5 * minutes;
        double minuteHandAngle = 6 * minutes;

        double angle = abs(minuteHandAngle - hourHandAngle);

        return min(angle, 360.0 - angle);
    }
};
