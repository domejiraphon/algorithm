/*
1344. Angle Between Hands of a Clock
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.
*/
class Solution {
public:
  double angleClock(int hour, int minutes) {
    hour %= 12;
    double posH = (double) hour / 12 * 360;
    posH += (double) minutes / 60 * 30;
    double posM = (double) minutes * 6;
    posH = abs(posH  - posM);
   
    return min(posH, 360 - posH);
  }
};
