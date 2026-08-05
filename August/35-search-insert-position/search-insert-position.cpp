class Solution {
public:

    int getIndex(vector<int>&nums, int target){
        int lo = 0;
        int hi = nums.size()-1;

        int ans = nums.size();

        while(lo<=hi){
            int mid = (lo+hi)/2;

            if(nums[mid] >= target){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }

    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        auto index = getIndex(nums,target);
        return index;
    }
};