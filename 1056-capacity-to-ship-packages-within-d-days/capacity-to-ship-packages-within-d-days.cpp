class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int left = 0; // search window starts from max weight (min capacity ship needs support)

        int right = 0; // search window ends at the total weight present in weights array

        for(auto w: weights){
            left = max(w, left);
            right += w;
        }


        while (left <= right ){
            int mid = left + (right-left) /2;

            if (isFeasible(weights,days, mid) ){
                // this capacity is capable to ship within days
                // decrease search window till mid
                right = mid-1;
            }
            else{
                // move search window leftward
                left = mid + 1;
            }
        }

        return left;
        

    }

private:
    bool isFeasible(const vector<int>& weights, const int days,int capacity){

        int day=1;
        int total = 0;

        for (auto w: weights){
            total+=w;

            if (total > capacity){
                total = w; // reset total to current weight item
                day+=1; // weight cannot be fit within capacity, need another day

                if (day > days) return false; // cannot ship within days
            }   
        }

        return true; // possible to ship within days at this capacity


    }
};