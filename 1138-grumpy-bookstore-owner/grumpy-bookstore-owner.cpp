class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int start=0, end=minutes-1;
        int n = grumpy.size();
        int maxSatisfied=0;

        // if minutes is more than customers length then all customers are happy
        if (minutes>=n) {
            for (int& i: customers){
                maxSatisfied+=i;
            }
            return maxSatisfied;
        }

        int alreadySatisfied=0;
        // calculate customers that are already happy , mark as 0 once customer has been added
        for (int i=0; i<n ;i++){
            if (grumpy[i] == 0){
                alreadySatisfied += customers[i];
                customers[i] = 0;
            }
        }

        // using the minutes as a rolling sum, we calculate the max customers to be happy
        int currentSatisfied=0;

        for(int i=0; i<n; i++) {
            currentSatisfied += customers[i];
            if (i>=minutes) {
                // remove no of customers outside the window
                currentSatisfied -= customers[i-minutes];

            }
            maxSatisfied = max(maxSatisfied, currentSatisfied);
        }

        return maxSatisfied + alreadySatisfied;


    

        
    }
};