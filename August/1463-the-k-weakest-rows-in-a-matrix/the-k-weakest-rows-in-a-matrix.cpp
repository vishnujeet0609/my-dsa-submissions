class Solution {
public:

    int getStrength(int row, vector<vector<int>>& mat ){
        int lo = 0;
        int hi = mat[row].size()-1;
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(mat[row][mid] == 1){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return lo;
        
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int,int>>pq;

        for(int i = 0; i < n; i ++){
            int strength = getStrength(i, mat);
            pq.push({strength, i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int>ans;
        for(int i = 0;i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};