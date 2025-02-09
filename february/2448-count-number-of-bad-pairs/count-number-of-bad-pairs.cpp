class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long badPairs = 0;
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++){
            int diff = nums[i]-i;
            int good_pairs = mp[diff];
            int total_pairs = i;
            badPairs+=total_pairs-good_pairs;
            mp[diff]++;
            
        }
        return badPairs;
    }
};