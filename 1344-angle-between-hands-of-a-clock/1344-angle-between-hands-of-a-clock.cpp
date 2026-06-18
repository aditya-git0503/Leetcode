class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs(5.5*minutes - 30 * hour);
        return ans > 180 ? 360 - ans : ans;
    }
};