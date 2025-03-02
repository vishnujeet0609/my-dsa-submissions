class Solution {
public:
    vector<vector<int>>result;
    int n;
    void backtrack(vector<int>& nums,vector<int>&curr, int idx){
        if(curr.size()>1){
            result.push_back(curr);
        }
        unordered_set<int>st;
        for(int i = idx; i<n;i++){
            if((curr.empty() || curr.back()<=nums[i])&& st.find(nums[i]) == st.end()){
                curr.push_back(nums[i]);
                backtrack(nums,curr,i+1);
                curr.pop_back();
                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int>curr;
        backtrack(nums,curr,0);
        return result;
    }
};