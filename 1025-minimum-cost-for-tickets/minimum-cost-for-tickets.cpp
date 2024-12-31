class Solution {
public:
    int getNextDayIndex(int ind,vector<int>& days,int passDuration){
        for(int i=ind+1;i<days.size();i++){
            if(days[i]>(days[ind]+passDuration-1)) return i;
        }
        return days.size();
    }
    int minCostUtil(int ind,vector<int>& days,vector<int>& costs,vector<int>&passDurations,vector<int>&dp)
    {
        if(ind==days.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int minCost = INT_MAX;
        for(int i=0;i<3;i++){
            int nextDayIndex = getNextDayIndex(ind,days,passDurations[i]);
            int travelCost = costs[i] + minCostUtil(nextDayIndex,days,costs,passDurations,dp);
            minCost = min(minCost,travelCost);
        }
        return dp[ind]=minCost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>passDurations={1,7,30};
        vector<int>dp(n,-1);
        return minCostUtil(0,days,costs,passDurations,dp);
    }
};