class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
  
        unordered_map<int, int> countMap;
        unordered_map<int, int> totalMap;

        countMap[0] = 1;
        totalMap[0] = -1;
        
        int ans = 0;
        int pxor = 0;
        
        for(int i = 0; i < n; i++) {
            pxor ^= arr[i];
            
            if(countMap.find(pxor) != countMap.end()) {
                ans += countMap[pxor] * (i - 1) - totalMap[pxor];
            }
            
            countMap[pxor]++;
            totalMap[pxor] += i;
        }
        
        return ans;
    }
};