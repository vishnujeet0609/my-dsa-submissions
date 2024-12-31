class Solution {
public:
    bool isAllStars(string s, int l){
        for(int i=0;i<=l;i++){
            if(s[i]!='*') return false;
        }
     return true;
      
    }
    bool isMatchUtil(int i , int j ,string &s, string &p, vector<vector<int>>&dp){
        if(i<0 && j<0){
            return true;
        }
        if(i<0 && j>=0){
            return false;
        }
        if(i>=0 && j<0 ){
            return isAllStars(s,i);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == p[j] || s[i]=='?'){
            return dp[i][j] = isMatchUtil(i-1,j-1,s,p,dp);
        }else{
            if(s[i]=='*'){
                return dp[i][j] = isMatchUtil(i-1,j,s,p,dp) || isMatchUtil(i,j-1,s,p,dp);
            }
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n= s.size();
        int m = p.size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return isMatchUtil(m-1,n-1,p,s,dp);
         vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
         dp[0][0]=true;
         
         for(int i=1;i<=m;i++){
            dp[i][0]= isAllStars(p,i-1);
         }
         for(int i=1;i<=n;i++){
            dp[0][i]=false;
         }
         for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    if(p[i-1]=='*')
                        dp[i][j]= dp[i-1][j] || dp[i][j-1];
                    else 
                        dp[i][j]=false;
                }
            }
         }
    return dp[m][n];
    }
};