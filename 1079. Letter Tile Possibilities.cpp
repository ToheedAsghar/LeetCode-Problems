#define TileSet unordered_set<string> 
class Solution {
TileSet visited;

void solve(string temp, const string& tiles, vector<bool> seen){
    if(visited.find(temp) != visited.end()) { return; }

    visited.insert(temp);

    int n = tiles.size();
    for(int i=0; i<n; i++){
        if(false == seen[i]){
            seen[i] = true;
            solve(temp+tiles[i], tiles, seen);
            seen[i] = false;
        }
    }        
}
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> seen (n, false);

        solve("", tiles, seen);
        return visited.size() - 1;
    }
};

// #include <bits/stdc++.h>
// using namespace std;

// #define SIZE 40000 + 11



// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     string tiles; cin >> tiles;

//     int n = tiles.size();
//     vector<bool> seen (n, false);
//     int cnt = 0;

//     solve("", tiles, seen, cnt);

//     cout << visited.size() - 1<< '\n';
//     // cout << cnt << '\n';

//     // for(const auto& it: visited){
//     //     cout << it << '\n';
//     // } cout << '\n';

//     return 0;
// }
