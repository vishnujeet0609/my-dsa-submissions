class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            mp[val] = i;
        }
        int minIndex = INT_MAX;
        for (int row = 0; row < mat.size(); row++) {
            int lastIndex = INT_MIN;
            for (int col = 0; col < mat[0].size(); col++) {
                int val = mat[row][col];
                int currIndex = mp[val];
                lastIndex = max(currIndex, lastIndex);
            }
            minIndex = min(minIndex, lastIndex);
        }

        for (int col = 0; col < mat[0].size(); col++) {
            int lastIndex = INT_MIN;
            for (int row = 0; row < mat.size(); row++) {
                int val = mat[row][col];
                int currIndex = mp[val];
                lastIndex = max(currIndex, lastIndex);
            }
            minIndex = min(minIndex, lastIndex);
        }
        return minIndex;
    }
};