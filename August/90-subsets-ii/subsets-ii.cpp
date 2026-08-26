class Solution {
public:

    int n;

    void solve(int idx, vector<int>& nums, vector<int>&cur, vector<vector<int>>&ans){

        if(idx>=n){
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[idx]);
        solve(idx+1,nums,cur,ans);
        cur.pop_back();

        while(idx+1 < n && nums[idx]==nums[idx+1]){
            idx+=1;
        }
        solve(idx+1, nums, cur, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>cur;

        solve(0, nums, cur, ans);

        return ans;

    }
};