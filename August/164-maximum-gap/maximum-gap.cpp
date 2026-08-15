class Solution {
public:
    void countingsort(vector<int>& nums, long long exp) {
        int n = nums.size();

        vector<int> output(n, 0);
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            count[(nums[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;
            output[count[digit] - 1] = nums[i];
            count[digit]--;
        }
        for (int i = 0; i < n; i++) {
            nums[i] = output[i];
        }
    }
    void radixSort(vector<int>& arr) {
        if (arr.empty())
            return;
        long long mx = *max_element(arr.begin(), arr.end());

        for (long long int exp = 1; mx / exp > 0; exp *= 10)
            countingsort(arr, exp);
    }
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;

        radixSort(nums);

        int diff = INT_MIN;

        for (int i = 0; i < nums.size() - 1; i++) {
            diff = max(diff, abs(nums[i] - nums[i + 1]));
        }

        return diff;
    }
};