class Solution {
public:
    vector<int>fact,arr;
    void solve(string &ans, int n, int k) {
      if(n==1){
        ans+=to_string(arr.back());
        return;
      }

      int blockSize = fact[n-1];
      int index = k/blockSize;
      if(k % blockSize == 0){
        index--;
      }
      ans+=to_string(arr[index]);
      arr.erase(arr.begin() + index);

      k-=(blockSize * index);
      solve(ans, n-1, k);
    }


    string getPermutation(int n, int k) {
        fact.push_back(1);
        int f = 1;
        for(int i =1;i<=n;i++){
            f*=i;
            fact.push_back(f);
        }
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        string ans = "";
        solve(ans, n, k);
        return ans;
        
    }
};