class Solution {
public:
    int countPrimes(int n) {
        vector<int>isPrime(n,1);
        if(n>0)
            isPrime[0] = 0; 
        if(n>1)
            isPrime[1] = 0;
        
        for(int i=2;i*i<n;i++){
            if(isPrime[i]){
                for(int j = i*i ; j<n;j+=i ){
                    isPrime[j] = 0;
                }
            }
        }
        
        int cnt= 0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                cnt++;
            }
        }
        return cnt;
    }
};