#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[n - 1][m - 1] == 1)
            return 0;

        vector<vector<int>> sol(n, vector<int>(m, 0));
        sol[0][0] = 1;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m;j++){
                if(validPos(i,j-1,obstacleGrid)){
                    sol[i][j] += sol[i][j - 1];
                }
                if(validPos(i-1,j,obstacleGrid)){
                    sol[i][j] += sol[i-1][j];
                }
            }
        }
        return sol[n - 1][m - 1];
    }

    bool validPos(int x, int y,vector<vector<int>>& obstacleGrid){
        return !(x < 0 || x >= obstacleGrid.size() || y < 0 || y >= obstacleGrid[0].size() || obstacleGrid[x][y] == 1);
    }
};