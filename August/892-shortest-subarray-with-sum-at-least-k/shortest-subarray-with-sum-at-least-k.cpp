class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>prefSum(n,0);
        for(int i = 0; i < n; i++){
            if(i==0){
                prefSum[i] = nums[i];
            }else{
                prefSum[i] += prefSum[i-1] + nums[i];
            }
        }

        deque<int>dq;
        int ans = INT_MAX;

        for(int i = 0; i < n ; i++){
            if(prefSum[i] >= k){
                ans = min(ans, i+1);
            }

            while(!dq.empty() && prefSum[i] - prefSum[dq.front()] >= k){
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefSum[dq.back()] >= prefSum[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};