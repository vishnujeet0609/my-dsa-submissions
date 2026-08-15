class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
         int n = nums.size();
        
        int curSumForMax = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        int curSumForMin = 0;
        int total = 0;
        
        for(int i = 0;i<n; i++){
            curSumForMax = max(curSumForMax + nums[i], nums[i]);
            maxSum = max(curSumForMax, maxSum);
            
            curSumForMin = min(curSumForMin + nums[i], nums[i]);
            minSum = min(curSumForMin, minSum);
            
            total += nums[i];
        }
        
        if(maxSum < 0){
            return maxSum;
        }
        
        return max(maxSum, total - minSum);
    }
};