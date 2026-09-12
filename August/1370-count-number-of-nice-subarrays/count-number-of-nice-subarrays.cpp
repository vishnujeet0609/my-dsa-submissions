class Solution {
public:
    int atMost(vector<int>& arr, int k) {
        if (k < 0) return 0;
        
        int n = arr.size();
        int head = -1;
        int oddCnt = 0;
        int tail = 0;
        int ans = 0; 
        
        while(tail < n) {
            while(head + 1 < n && oddCnt + (arr[head + 1] % 2 != 0 ? 1 : 0) <= k) {
                head++;
                if(arr[head] % 2 != 0) {
                    oddCnt++;
                }
            }
            
            ans += (head - tail + 1);
         
            if(tail > head) {
                tail++;
                head = tail - 1;
            } else {
                if(arr[tail] % 2 != 0) {
                    oddCnt--;
                }
                tail++;
            }
        }
        
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};