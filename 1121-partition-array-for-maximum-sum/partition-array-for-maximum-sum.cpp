class Solution {
public:
    int n;
    int f(int ind, vector<int>&arr, int k, vector<int>&dp){
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int maxi = INT_MIN;
        int maxSum = INT_MIN;
        int len =0;
        for(int i=ind;i<min(ind+k,n);i++){
            len++;
            maxi = max(maxi,arr[i]);
            int sum = len*maxi + f(i+1,arr,k,dp);
            maxSum = max(maxSum,sum);

        }
        return dp[ind]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int>dp(n,-1);
        int ans = f(0,arr,k,dp);
        return ans;
    }
};