class Solution {
public:
    int countUtil(int i, int j, vector<int> &cuts,vector<vector<int>>&dp){
            if(i>j) return 0;
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            long mini = INT_MAX;
            for(int k=i;k<=j;k++){
                long ans = cuts[j+1]-cuts[i-1] + countUtil(i,k-1,cuts,dp)+ countUtil(k+1,j,cuts,dp);
                mini = min(mini,ans);
            }
            return dp[i][j]=mini;
    }

    int minCost(int n, vector<int>& cuts) {
      int c = cuts.size();
      cuts.push_back(n);
      cuts.insert(cuts.begin(),0);
      sort(cuts.begin(),cuts.end());
      vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
      int ans =countUtil(1,c,cuts,dp);
      return ans;
    }
};