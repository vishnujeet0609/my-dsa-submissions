class Solution {
public:
// memmoization
bool isPalindrome(int i, int j, string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
       return true;
}
int countUtil(int i, int n , string &s, vector<int>&dp){
    if(i==n) return 0;
    if(dp[i]!=-1)return dp[i];
    int mini = INT_MAX;
    for(int k=i;k<=n-1;k++){
        if(isPalindrome(i,k,s)){
            int cost = 1 + countUtil(k+1,n,s,dp);
            mini = min(mini,cost);
        }
    }
    return dp[i]=mini;
;}
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n+1,0);
        // int ans = countUtil(0,n,s,dp);
        // return ans-1;
        //tabulation
        for(int i=n-1;i>=0;i--){
            int mini = INT_MAX;
            for(int k=i;k<=n-1;k++){
                if(isPalindrome(i,k,s)){
                    int cost = 1 + dp[k+1];
                    mini = min(mini,cost);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;

    }

};