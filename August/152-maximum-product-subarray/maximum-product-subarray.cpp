class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProd = *max_element(nums.begin(),nums.end());
        int curMinProd = 1;
        int curMaxProd = 1;;

        for(int i = 0;i<n;i++){
            int temp = curMaxProd*nums[i];
            curMaxProd = max({temp, curMinProd * nums[i], nums[i]});
            curMinProd = min({temp, curMinProd * nums[i], nums[i]});

            maxProd = max(maxProd, curMaxProd);
        }
        return maxProd;
    }
};