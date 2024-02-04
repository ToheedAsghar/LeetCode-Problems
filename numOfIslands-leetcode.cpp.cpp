// https://leetcode.com/problems/number-of-islands/description/

#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>>& grid);

int main(){
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    cout << numIslands(grid);
    return 0;
}

void floodFill(vector<vector<char>>& grid, int i, int j){
    int n = grid.size();        // rows
    int m = grid[0].size();     // cols

    queue<pair<int, int>> que;
    que.push({i,j});
    while(!que.empty()){
        pair<int, int> temp = que.front();
        que.pop();
        if('1' == grid[temp.first][temp.second]){
            grid[temp.first][temp.second] = '2';
            // pushing it's valid neighbours to the que
            if(temp.first-1 >= 0) que.push({temp.first-1, temp.second});
            if(temp.first+1 < n) que.push({temp.first + 1, temp.second});
            if(temp.second-1 >= 0) que.push({temp.first, temp.second-1});
            if(temp.second+1 < m) que.push({temp.first, temp.second+1});
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            if('1' == grid[i][j]){
                cnt++;
                floodFill(grid, i, j);
            }
        }
    }
    return cnt;
}