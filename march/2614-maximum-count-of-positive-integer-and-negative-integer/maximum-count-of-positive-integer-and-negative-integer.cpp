
//Approach-1 (Using STL count_if())
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {

        auto lambdaP = [](int num) {
            return num > 0;
        };

        auto lambdaN = [](int num) {
            return num < 0;
        };

        int countPositive = count_if(begin(nums), end(nums), lambdaP);
        int countNegative = count_if(begin(nums), end(nums), lambdaN);

        return max(countPositive, countNegative);
    }
};


//Approach-2 (Using lowerbound)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int firstP = lower_bound(begin(nums), end(nums), 1) - begin(nums);
        int firstN = lower_bound(begin(nums), end(nums), 0) - begin(nums);

        return max(n-firstP, firstN);
        
    }
};


/*********************************************************** C++ **************************************************/
//Approach-1 (Using stream , filter and count)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maximumCount(int[] nums) {
        
        IntPredicate lambdaP = num -> num > 0;
        IntPredicate lambdaN = num -> num < 0;
        
        int positiveCount = (int) Arrays.stream(nums).filter(lambdaP).count();
        int negativeCount = (int) Arrays.stream(nums).filter(lambdaN).count();

        return Math.max(positiveCount, negativeCount);
        
    }
}



//Approach-2 (Using lowerbound)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int apnaLowerBound(vector<int>& nums, int l, int r,int k){
       int result = nums.size();
        while(l<=r){
            int mid  = l + (r-l)/2;
            if(nums[mid]<k){
                l = mid + 1;
            }else{
                result = mid;
                r = mid -1;
            }
        }
        return result;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int firstP = apnaLowerBound(nums,0,n-1,1);
        int firstN = apnaLowerBound(nums,0,n-1,0);
        return max(n-firstP,firstN);
    }
};
