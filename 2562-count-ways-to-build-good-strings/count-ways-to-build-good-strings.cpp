class Solution {
public:
    int mod = 1e9+7;
    int countUtil(int target, int zero,int one,vector<int>&dp){
        if(target==0)return 1;
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        int pickOne = countUtil(target-one,zero,one,dp);
        int pickZero = countUtil(target-zero,zero,one,dp);
        return dp[target]=((pickOne %mod) + (pickZero % mod))%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        long long ans=0;
        for(int i=low;i<=high;i++){
            ans=((ans%mod)+countUtil(i,zero,one,dp)%mod)%mod;
        }
        return ans;
    }
};