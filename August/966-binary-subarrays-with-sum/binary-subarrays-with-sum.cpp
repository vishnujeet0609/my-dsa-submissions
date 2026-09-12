class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int n = nums.size();
        int head = -1;
        int currentSum = 0;
        int tail = 0;
        int ans = 0; 
        
        while(tail < n) {
            while(head + 1 < n && currentSum + nums[head + 1] <= goal) {
                head++;
                currentSum += nums[head];
            }
    
            if(head >= tail) {
                ans += (head - tail + 1);
            }
            
            if(tail > head) {
                tail++;
                head = tail - 1;
            } else {
                currentSum -= nums[tail];
                tail++;
            }
        }
        
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};