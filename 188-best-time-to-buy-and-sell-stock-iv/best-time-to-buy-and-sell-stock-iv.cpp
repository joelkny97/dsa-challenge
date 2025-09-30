class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> buying (k, INT_MAX);
        vector<int> selling (k, 0);

        for (int i=0; i<n; i++) {
            
            for (int j=0; j<k; j++ ){
                if (j==0){
                    buying[j] = min(buying[j], prices[i]);
                }
                else{
                    buying[j] = min(buying[j],prices[i]-selling[j-1]);
                }
                selling[j] = max(selling[j], prices[i]-buying[j]);
            }
                
        }
        
        return selling[k-1];
    }
};