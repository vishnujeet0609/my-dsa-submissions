class Solution {
public:
    int getSumOfDigits(int n){
        int sum = 0;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int sumOfDigitsi = getSumOfDigits(nums[i]);
            if(mp.count(sumOfDigitsi)>0){
                int sum = nums[i]+mp[sumOfDigitsi];
                result = max(result,sum);
            }
            mp[sumOfDigitsi] = max(mp[sumOfDigitsi],nums[i]);
        }
        return result;
    }
};