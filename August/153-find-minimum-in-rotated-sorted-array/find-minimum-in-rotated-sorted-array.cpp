class Solution {
public:

    int check(vector<int>&nums,int mid){
        if(nums[nums.size()-1] >= nums[mid]){
            return 1;
        }
        return 0;
    }

    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;

        int ans = nums[0];

        while(lo<=hi){
            int mid = (lo+hi)/2;

            if(check(nums,mid)){
                ans = nums[mid];
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};