//T.C : O(n)
//S.C : O(1) in place
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        for(int &num : arr) {
            int val = (num & 65535);

            if(val <= n) {
                arr[val-1] += (1<<16); //65536, pow(2, 16)
            }
        }

        for(int val = n; val >= 1; val--) {
            if((arr[val-1] >> 16) == val) {
                return val;
            }
        }

        return -1;
    }
};
