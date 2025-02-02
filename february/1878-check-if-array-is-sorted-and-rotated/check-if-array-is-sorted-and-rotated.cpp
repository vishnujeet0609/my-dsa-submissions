//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int peak = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i+1)%n]) {
                peak++;
            }
        }

        return peak <= 1;
    }
};

//Approach-1 (Super Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted(n);

        for(int r = 0; r < n; r++) {

            int idx = 0;
            for(int i = r; i < n; i++) {
                sorted[idx] = nums[i];
                idx++;
            }

            for(int i = 0; i < r; i++) {
                sorted[idx] = nums[i];
                idx++;
            }

            //check if sorted;
            bool isSorted = true;
            for(int i = 0; i < n-1; i++) {
                if(sorted[i] > sorted[i+1]) {
                    isSorted = false;
                    break;
                }
            }

            if(isSorted) {
                return true;
            }

        }

        return false;
    }
};


//Approach-2 (Better Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));

        for(int r = 0; r < n; r++) {
            bool isSorted = true;
            for(int i = 0; i < n; i++) {
                if(sorted[i] != nums[(i + r)%n]) {
                    isSorted = false;
                    break;
                }
            }

            if(isSorted) {
                return true;
            }

        }

        return false;
    }
};
