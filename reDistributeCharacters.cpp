// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

#include <bits/stdc++.h>
using namespace std;

bool makeEqual(vector<string>& words);

int main(){
    vector<string> str = {"ab" , "a"};
    cout << makeEqual(str) << endl;
    return 0;
}

bool makeEqual(vector<string>& words) {
    bool retVal;
    vector<int> hashTable(26,0);

    for(int i=0; i<words.size(); i++){
        for(int j=0; j<words[i].size(); j++){
            char c = words[i][j];
            hashTable[c-'a']++;
        }
    }

    int n = words.size();
    for(int i=0; i<26; i++){
        if(0 != hashTable[i] && hashTable[i]%n != 0){
            return false;
        }
    }

    return true;
}