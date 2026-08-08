class Solution {
public:
    bool check(vector<vector<int>>& matrix,int n,int m ,int target){
        int row = 0;
        int col = m-1;

        while(row<n && col>=0){
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] > target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        return check(matrix,n,m,target);
    }
};