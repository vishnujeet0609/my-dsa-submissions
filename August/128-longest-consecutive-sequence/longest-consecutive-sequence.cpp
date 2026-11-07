class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        unordered_set<int>st;

        for(int i = 0; i< n;i++){
            st.insert(nums[i]);
        }

        for(auto v : st){
            if(st.find(v-1) == st.end()){
                int res = 0;
                int cur = v;
                while(st.find(cur) != st.end()){
                    res++;
                    cur += 1;
                }
                ans = max(ans, res);
            }
        }
        return ans;
    }
};