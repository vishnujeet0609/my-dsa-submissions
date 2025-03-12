class Solution {
public:
    int apnaLowerBound(vector<int>& nums, int l, int r,int k){
       int result = nums.size();
        while(l<=r){
            int mid  = l + (r-l)/2;
            if(nums[mid]<k){
                l = mid + 1;
            }else{
                result = mid;
                r = mid -1;
            }
        }
        return result;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int firstP = apnaLowerBound(nums,0,n-1,1);
        int firstN = apnaLowerBound(nums,0,n-1,0);
        return max(n-firstP,firstN);
    }
};