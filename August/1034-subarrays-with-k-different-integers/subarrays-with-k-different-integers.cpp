class Solution {
public:

    int atMost(vector<int>& arr, int k){
        int n = arr.size();
        int tail = 0;
        int head = -1;
        map<int,int>mp;
        long long ans = 0;
        while(tail<n){
            while(head+1<n && (mp.find(arr[head+1])!=mp.end() || mp.size() < k)){
                head++;
                mp[arr[head]]++;
            }
            ans += head- tail +1;
            if(tail>head){
                tail++;
                head = tail-1;
            }else{
                mp[arr[tail]]--;
                if(mp[arr[tail]]==0){
                    mp.erase(arr[tail]);
                }
                tail++;
            }
        }
    return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums,k-1);
    }
};