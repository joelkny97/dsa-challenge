class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (startValue == target) return 0;
        if (startValue > target){
            // if startVal greater, then can only reached by start-target number of -1 operations  
            return startValue - target;
        }
        int count=0;
        while (startValue != target) {

            if (startValue >= target) return (startValue-target)+count;
            // if divisble by 2 then divide by 2
            
            if (target % 2 == 0) {
                target /= 2;
            }
            // add 1 to it
            else {
                target += 1;
                
            }
            count++;
            

        }

        return count;
    }
};