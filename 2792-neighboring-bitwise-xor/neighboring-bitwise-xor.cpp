class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        bool flag = false;
        vector<int>result(n,-1);
        for(int i=0;i<=1;i++){
            result[0]=i;
            for(int j=1;j<n;j++){
                result[j]=result[j-1]^derived[j-1];
            }
            if(result[0]^result[n-1]==derived[n-1]){
                flag = true;
                break;
            }
        }
        return flag;
    }
};