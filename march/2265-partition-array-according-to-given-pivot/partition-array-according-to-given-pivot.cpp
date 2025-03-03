class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int i_ = 0;
        int j_ = n-1;
        vector<int>result(n);
        while(i<n && j>=0){
            if(nums[i] < pivot){
                result[i_]=nums[i];
                i_++;
            }
            if(nums[j] > pivot){
                result[j_] = nums[j];
                j_--;
            }
            i++;
            j--;
        }
        while(i_<=j_){
            result[i_] = pivot;
            i_++;
        }
        return result;
    }
};