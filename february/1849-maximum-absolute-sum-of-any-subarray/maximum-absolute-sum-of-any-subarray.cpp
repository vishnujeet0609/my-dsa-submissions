//T.c = o(n);
//s.c = o(1);

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int currSumMax = nums[0];
        int currSumMin = nums[0];
        int maxSubArrSum = nums[0];
        int minSubArrSum = nums[0];
        //kadane's algo for max sub array sum
        for(int i=1;i<n;i++){
            currSumMax = max(nums[i],currSumMax+nums[i]);
            maxSubArrSum = max(maxSubArrSum,currSumMax);

            currSumMin = min(nums[i],currSumMin+nums[i]);
            minSubArrSum = min(minSubArrSum,currSumMin);
            
        }
        return max(abs(maxSubArrSum),abs(minSubArrSum));
    }
};