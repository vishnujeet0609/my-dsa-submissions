class Solution {
public:
    vector<int> sieve(int right){
        vector<int>arr(right+1,1);
        arr[0]=0;
        arr[1]=0;
        for(int i = 2;i*i<=right;i++){
            if(arr[i]==1){
                for(int multiple = i*i;multiple<=right;multiple+=i){
                    arr[multiple]=0;
                }
            }
        }
        return arr;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>sieveArray = sieve(right);
        vector<int>primeNumbers;
        for(int i=left;i<sieveArray.size();i++){
            if(sieveArray[i]==1){
                primeNumbers.push_back(i);
            }
            
        }
        if(primeNumbers.size()<2){
                return {-1,-1};
        }
        int mindiff = INT_MAX;
        vector<int>ans(2,-1);
        for(int i =1;i<primeNumbers.size();i++){
           int diff = primeNumbers[i]-primeNumbers[i-1];
           if(diff<mindiff){
            mindiff=diff;
            ans[0]=primeNumbers[i-1];
            ans[1]=primeNumbers[i];
           }

        }
        return ans;
    }
};