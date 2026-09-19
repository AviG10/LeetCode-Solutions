class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        int nearestX, nearestY;

        if (xCenter < x1)
            nearestX = x1;
        else if (x2 < xCenter)
            nearestX = x2;
        else
            nearestX = xCenter;

        if (yCenter < y1)
            nearestY = y1;
        else if (y2 < yCenter)
            nearestY = y2;
        else
            nearestY = yCenter;

        int dist = sqrt((nearestX - xCenter) * (nearestX - xCenter) +
                        (nearestY - yCenter) * (nearestY - yCenter));

        return (dist <= radius);
    }
};