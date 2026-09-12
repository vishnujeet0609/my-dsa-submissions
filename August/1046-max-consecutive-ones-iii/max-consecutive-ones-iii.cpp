class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int head=0;
        int ans=0;
        int flipcnt=0;

        for(int tail=0;tail<n;tail++){
            while(head<n && (nums[head]==1 || flipcnt < k)){
                if(nums[head]==0){
                    flipcnt++;
                }
                head++;
            }
            ans = max(ans, head-tail);
            if(nums[tail]==0){
                flipcnt--;
            }
        }
       return ans;
    }
};