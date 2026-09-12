class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right= n-1;
        int ans = 0;
        while(left<right){
            int curHeight = min(height[left], height[right]);
            int curWidth = right-left;
            ans = max(ans, curHeight * curWidth);

            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};