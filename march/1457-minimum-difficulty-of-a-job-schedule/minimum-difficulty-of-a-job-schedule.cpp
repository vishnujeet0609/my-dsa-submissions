class Solution {
public:
    int arr[11][301];
    int solve(vector<int>& jobDifficulty, int d, int idx,int n){
        if(d==1){
            return *max_element(begin(jobDifficulty)+idx,end(jobDifficulty));
        }
        if(arr[d][idx]!=-1){
            return arr[d][idx];
        }

        int maxjobdifficulty = INT_MIN;
        int result = INT_MAX;
        for(int i = idx; i<=n-d;i++){
            maxjobdifficulty = max(maxjobdifficulty,jobDifficulty[i]);
            result = min(result, maxjobdifficulty + solve(jobDifficulty,d-1,i+1,n));   
        }
        return arr[d][idx]=result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int  n = jobDifficulty.size();
        memset(arr,-1,sizeof(arr));
        if(n<d) return -1;
        return solve(jobDifficulty,d,0,n);

    }
};