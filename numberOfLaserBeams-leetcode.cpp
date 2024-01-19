// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string>& bank);

int main(){
    // Time Complexity O(n*m)

    // {"000","111","000"}
    vector<string> bank = {"011001", "000000", "010100", "001000"};
    cout << numberOfBeams(bank) << endl;
    return 0;
}

int numberOfBeams(vector<string>& bank) {
    int m = bank.size();    // rows
    int n = bank[0].size(); // columns
    vector<int> ones;

    for(int i=0; i<m; i++){
        int tempOnes = 0;
        bool flag = false;
        for(int j=0; j<n; j++){
            int t = bank[i][j] - 48;
            if(t == 1){
                tempOnes++;
                flag = true;
            }
        }
        if(flag){
            ones.push_back(tempOnes);
        }
    }


    int beams = 0;
    int l = ones.size();
    for(int i = l-1; i>0; i--){
        beams += ones[i]* ones[i-1];
    }

    return beams;
}