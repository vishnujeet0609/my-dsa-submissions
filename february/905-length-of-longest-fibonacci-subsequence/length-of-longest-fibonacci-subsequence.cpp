class Solution {
public:
    int solve(int j, int k, vector<int>& arr, unordered_map<int, int>& mp,
              vector<vector<int>>& dp) {
        if(dp[j][k]!=-1){
            return dp[j][k];
        }
        int target = arr[k]-arr[j];
        if(mp.count(target) && mp[target]<j){
            int i = mp[target];
            return dp[j][k] = solve(i,j,arr, mp,dp) +1;
        }
        return dp[j][k]=2;
      }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        int maxLength = 0;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                int length = solve(j, k, arr, mp, dp);
                if (length >= 3)
                    maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
};