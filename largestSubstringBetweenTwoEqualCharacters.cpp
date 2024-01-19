// 1624. Largest Substring Between Two Equal Characters
// https://leetcode.com/problems/largest-substring-between-two-equal-characters/description

#include <bits/stdc++.h>
using namespace std;

int maxLengthBetweenEqualCharacters(string s);

int main(){
    // abca aa cbzxy
    string s = "abca";
    cout << maxLengthBetweenEqualCharacters(s);
}

int maxLengthBetweenEqualCharacters(string s) {
    unordered_map<char, vector<int>> arr;

    for(int i=0; i<s.length(); i++){
        arr[s[i]].push_back(i);
    }

    // displaying the map
    // for(const auto val: arr){
    //     cout << val.first << " ";
    //     for(auto j: val.second){
    //         cout << j << " ";
    //     }  cout << endl;
    // }

    int maxLength = 0;
    for(const auto val: arr){
        int temp = 0;
        temp = val.second[val.second.size()-1] - val.second[0];
        maxLength = max(maxLength, temp);
    }

    return maxLength-1;
}