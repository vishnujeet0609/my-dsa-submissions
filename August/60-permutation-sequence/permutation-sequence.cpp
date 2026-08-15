class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),k,l;
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1])break;
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        } else{
        for(l=n-1;l>=k+1;l--){
            if(nums[l]>nums[k])break;
        }
        
        swap(nums[k],nums[l]);
        reverse(nums.begin()+k+1,nums.end());
        }
    }


    string getPermutation(int n, int k) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        for(int i=1; i<k;i++){
            nextPermutation(arr);
        }
        string s = "";

        for(int i=0;i<n;i++){
            int digit = arr[i];
            s+=to_string(digit);
        }
        return s;
    }
};