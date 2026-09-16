class Solution {
public:
    
    vector<int> nextSmallerLeft(vector<int>& heights,int n){
        vector<int>nsl;
        stack<pair<int,int>>st;

        for(int i = 0; i < n ; i++){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                nsl.push_back(-1);
            }else{
                nsl.push_back(st.top().second);
            }
            st.push({heights[i], i});
        }
        return nsl;

    }
    
    vector<int> nextSmallerRight(vector<int>& heights,int n){
        vector<int>nsr(n);
        stack<pair<int,int>>st;

        for(int i = n-1; i >= 0 ; i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                nsr[i] = n;
            }else{
                nsr[i] = st.top().second;
            }
            st.push({heights[i], i});
        }
        return nsr;

    }

    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        vector<int>nsl = nextSmallerLeft(heights,n);
        vector<int>nsr = nextSmallerRight(heights,n);

        for(int i = 0; i < n; i++){
            int width = nsr[i] - nsl[i] - 1;
            int height = heights[i];

            maxArea = max(maxArea, width*height);
        }
        return maxArea;
    }
};