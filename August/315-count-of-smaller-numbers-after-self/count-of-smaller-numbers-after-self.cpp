class Solution {
public:

    void countMerge(vector<pair<int,int>>& v,int l,int m, int r, vector<int>&count){

        int n1 = m-l+1;
        int n2 = r-m;

        vector<pair<int,int>>left(n1);
        vector<pair<int,int>>right(n2);

        for(int i = 0;i <n1; i++){
            left[i] = v[l+i];
        }

        for(int i = 0;i <n2; i++){
            right[i] = v[m+1+i];
        }

        int i = 0;
        int j = 0;
        int k = l;

        int res = 0;
        while(i<n1 && j<n2){
            if(left[i].first <= right[j].first){
                v[k] = left[i];
                count[left[i].second]+=res; 
                i++;
                
            }else{
                v[k] = right[j];
                j++;
                res+=1;
            }
            k++;
        } 
        while(i<n1) {
            v[k] = left[i];
            count[left[i].second]+=res;
            k++;
            i++;
        }
        while(j<n2){
            v[k] = right[j];
            k++;
            j++;
        }

    }

    void solveCountSmaller(vector<pair<int,int>>& v,int l, int r, vector<int>&count){

        if(l<r){
            int mid = l + (r-l)/2;

            solveCountSmaller(v,l,mid,count);
            solveCountSmaller(v,mid+1,r,count);

            countMerge(v,l,mid,r,count);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>>v(n);

        for(int i = 0; i<n;i++){
            v[i] = {nums[i],i};
        }

        vector<int>count(n,0);
        solveCountSmaller(v,0,n-1,count);
        return count;
    }
};