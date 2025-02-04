class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = nums[0];
        int currSum = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currSum+=nums[i];
                maxi = max(maxi,currSum);
            }else{
                currSum=nums[i];
                maxi = max(maxi,currSum);
            }
        }
        return maxi;
    }
};