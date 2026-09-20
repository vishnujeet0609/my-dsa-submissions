class Solution {
public:

    vector<int> getNSR(vector<int>&height, int m){
        stack<int>st;
        vector<int>NSR(m);

        for(int i = m-1; i >= 0; i--){
            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }

            if(st.empty()){
                NSR[i] = m;
            }else{
                NSR[i] = st.top();
            }
            st.push(i);
        }
        return NSR;
    }

    vector<int> getNSL(vector<int>&height, int m){
        stack<int>st;
        vector<int>NSL(m);

        for(int i = 0; i < m; i++){
            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }

            if(st.empty()){
                NSL[i] = -1;
            }else{
                NSL[i] = st.top();
            }
            st.push(i);
        }
        return NSL;
    }

    int getMaxArea(vector<int>&height, int m){
        vector<int>NSL = getNSL(height,m);
        vector<int>NSR = getNSR(height,m);

        vector<int>width(m,0);

        for(int i = 0; i < m; i++){
            width[i] = NSR[i] - NSL[i] -1;
        }

        int maxArea = 0;
        for(int i = 0; i < m; i++){
            int area = width[i] * height[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>height(m,0);

        int maxArea = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }else{
                    height[j]+=1;
                }
            }
            maxArea = max(maxArea, getMaxArea(height , m));

        }
        return maxArea;
    }
};