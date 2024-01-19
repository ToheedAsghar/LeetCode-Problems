// link: https://leetcode.com/problems/game-of-life/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    vector<vector<int>> res;
    class cell{
        public:
            int x;
            int y;
            cell(int i, int j) : x(i), y(j){}
    };

public:
    void neighbours(const vector<vector<int>> board, cell c, int m, int n){
        if(c.x >= m || c.y >= n){
            return;
        }
        int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int col[] = {-1, 0, 1, 1, -1, -1, 0, 1};

        int cnt = 0;

        for(int i=0; i<8; i++){
            int r = c.x + row[i];
            int co = c.y + col[i];
            if(r >= 0 && r < m && co >= 0 && co < n){
                if(board[r][co] == 1){
                    cnt++;
                }
            }
        }

        if(board[c.x][c.y] == 1){
            if(cnt < 2){
                // cell dies
                res[c.x][c.y] = 0;
            }
            else if(cnt > 3){
                // cell dies
                res[c.x][c.y] = 0;
            }
        }
        else{
            if(cnt == 3){
                res[c.x][c.y] = 1;
            }
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        res = board;
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                neighbours(board, cell(i,j), m, n);
            }
        }
        board = res;
    }
};

int main(){
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    // display before game of Life
    for(const auto &it: board){
        for(const auto& ele: it){
            cout << ele << ' ';
        } cout << '\n';
    } cout << '\n';


    Solution sol;
    sol.gameOfLife(board);

    // display after game of Life
    for(const auto &it: board){
        for(const auto& ele: it){
            cout << ele << ' ';
        } cout << '\n';
    }

    return 0;
}