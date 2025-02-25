class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        //odd+even = odd
        //even+odd = odd
        int even = 1;
        int odd = 0;
        int sum = 0;
        int count = 0;
        for(int  i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                count=(count+odd)%M;
                even++;

            }else{
                count=(count+even)%M;
                odd++;
            }
        }
        return count;
    }
};