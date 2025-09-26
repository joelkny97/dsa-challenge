class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        
        int n = nums.size();
        int maxFreq = 0;
        for(int i=0; i<n; i++) {
            freq[nums[i]] += 1;
            maxFreq = max(freq[nums[i]], maxFreq);
        }

        // bucket sort to get top k frequencies from freq map
        vector<vector<int>> topk(maxFreq+1, (vector<int> ()));

        // create buckets of all element of all freqs
        for (auto &it : freq){
            topk[it.second].push_back(it.first);
        }

        vector<int> res;

        for (int i=maxFreq; i>0 && k > 0; i--) {
            if(topk[i].empty()) continue;
            
            for(int &j: topk[i]) {
                if (k==0) break;
                res.push_back(j);
                k--;
            }
            
        }

        return res;

    }
};