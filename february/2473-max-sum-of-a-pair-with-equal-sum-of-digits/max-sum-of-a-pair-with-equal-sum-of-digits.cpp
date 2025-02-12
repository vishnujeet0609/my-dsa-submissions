//Approach-1 (Brute Force)
//T.C : O(n^2 * m), m = number of digits
//S.C : O(1)
class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while(num > 0) {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        for(int i = 0; i < n; i++) {
            int digitSumi = getDigitSum(nums[i]);

            for(int j = i+1; j < n; j++) {
                int digitSumj = getDigitSum(nums[j]);

                if(digitSumi == digitSumj) {
                    result = max(result, nums[i] + nums[j]);
                }
            }
        }

        return result;
    }
};


//Approach-2 (Optimal using Map)
//T.C : O(n*m), m = number of digits
//S.C : O(n)
class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while(num > 0) {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            int digitSum = getDigitSum(nums[i]);

            if(mp.count(digitSum)) {
                result = max(result, nums[i] + mp[digitSum]);
            }

            mp[digitSum] = max(mp[digitSum], nums[i]);
        }

        return result;
    }
};


//Approach-2 (Optimal array as Map of constant size)
//T.C : O(n*m), m = number of digits
//S.C : O(1)

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
