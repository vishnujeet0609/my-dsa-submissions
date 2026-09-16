class Solution {
public:

    int mod = 1e9+7;

    vector<int> nextSmallerLeft(vector<int>& arr,int n){
        vector<int>nsl;
        stack<pair<int,int>>st;

        for(int i = 0; i < n ; i++){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                nsl.push_back(-1);
            }else{
                nsl.push_back(st.top().second);
            }
            st.push({arr[i], i});
        }
        return nsl;

    }
    
    vector<int> nextSmallerRight(vector<int>& arr,int n){
        vector<int>nsr(n);
        stack<pair<int,int>>st;

        for(int i = n-1; i >= 0 ; i--){
            while(!st.empty() && st.top().first > arr[i]){
                st.pop();
            }
            if(st.empty()){
                nsr[i] = n;
            }else{
                nsr[i] = st.top().second;
            }
            st.push({arr[i], i});
        }
        return nsr;

    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int>nsl = nextSmallerLeft(arr,n);
        vector<int>nsr = nextSmallerRight(arr,n);

        int sum = 0;

        for(int i = 0; i < n; i++){
            int cntStartBar = i - nsl[i];
            int cntEndBar = nsr[i] - i;
            sum = (sum + ((1LL * arr[i] * cntStartBar * cntEndBar) % mod) + mod) % mod;
        }
        return sum;
        
    }
};