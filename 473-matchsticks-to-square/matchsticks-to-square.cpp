class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        
        if (matchsticks.empty() || matchsticks.size() < 4) {
            return false;
        }

        int maxSide=0, side, sum=0;

        for (int &i: matchsticks) {
            sum += i;
            maxSide = max(i, maxSide);
        }
        
        // if a maxSide is greater than side or sum is not divisble by 4 then square cannot be formed
        side = sum/4; 

        if(maxSide > side || sum%4 != 0) {
            return false;
        }

        // store the side of each side of the square used to form the square
        array<int, 4> square({0,0,0,0});

        // sort the matchsticks array in desc order to get larger sides eliminated first 
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return backtrack(matchsticks, 0, square, side);
        
    }

private:
    bool backtrack(vector<int>& matchsticks, int idx, array<int, 4>& square, int length) {
        //base 
        if (idx == matchsticks.size()) return true;

        // logic
        for (int i=0; i<4; i++) {
            if (square[i] + matchsticks[idx] <= length){
                // action 
                square[i] += matchsticks[idx];

                //recurse
                if (backtrack(matchsticks, idx+1, square, length)) return true;

                //backtrack
                square[i] -= matchsticks[idx];
            }
        }

        return false;
    }
};