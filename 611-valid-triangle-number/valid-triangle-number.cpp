class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();

        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += j - i;
                    j -= 1;
                } else {
                    i += 1;
                }
            }
        }
        return count;
    }
};