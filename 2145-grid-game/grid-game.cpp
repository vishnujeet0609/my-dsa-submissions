class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainingPoints = accumulate(begin(grid[0]),end(grid[0]),0LL);
        long long minPointsRobot2 = LONG_LONG_MAX;
        long long secondRowRemainingPoints = 0;

        for(int robot1=0;robot1<grid[0].size();robot1++){
            firstRowRemainingPoints-=grid[0][robot1];
            minPointsRobot2 = min(minPointsRobot2,  max(firstRowRemainingPoints,secondRowRemainingPoints));
            secondRowRemainingPoints += grid[1][robot1];
        }
        return minPointsRobot2;
    }
};