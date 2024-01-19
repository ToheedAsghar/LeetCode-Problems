// https://leetcode.com/problems/minimum-falling-path-sum/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> memo; // for memoization
    class cell{
    public:
        int x, y;
        cell(){}
        cell(int x, int y) : x(x), y(y){}
    };

    int dfs(const vector<vector<int>>& matrix, cell dim, cell curr){
        if((curr.x == (dim.x) - 1)){
            return memo[curr.x][curr.y] = matrix[curr.x][curr.y];
        }

        int m = dim.y;
        if(INT_MIN == memo[curr.x][curr.y]){
            int leftD = INT_MAX, rightD = INT_MAX;
            if(curr.y > 0)
                leftD = dfs(matrix, dim, cell(curr.x + 1, curr.y-1));
            int down = dfs(matrix, dim, cell(curr.x + 1, curr.y));
            if(curr.y < m - 1)
                rightD = dfs(matrix, dim, cell(curr.x+1, curr.y + 1));

            memo[curr.x][curr.y] = min(leftD, min(rightD, down)) + matrix[curr.x][curr.y];
        }

        return memo[curr.x][curr.y];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        cell dim(n,m);

        memo = vector<vector<int>> (n, vector<int>(m, INT_MIN));

        int minSum = 99999999;
        for(int j=0; j<m; j++){
            minSum = min(minSum, dfs(matrix, dim, cell(0,j)));
        }

        return minSum;
    }
};

int main(){
    // {2,1,3},{6,5,4},{7,8,9}
    // {-19,57},{-40,-5}
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    Solution sol;
    cout << sol.minFallingPathSum(matrix);
    return 0;
}