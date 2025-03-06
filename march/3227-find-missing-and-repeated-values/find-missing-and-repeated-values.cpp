class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int,int>mp;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
        int repeated =0;
        int missing=0;
        for(int i =1;i<=n*n;i++){
            if(mp.find(i)!=mp.end()&&mp[i]==2){
                repeated = i;
            }
            if(mp.find(i)==mp.end()){
                missing = i;
            }
            if(repeated && missing){
                break;
            }
        }
        return {repeated,missing};
    }
};