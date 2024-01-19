// https://leetcode.com/problems/length-of-last-word/
#include <iostream>
#include <vector>
using namespace std;

int lengthOfLastWord(string s) {
        int n = s.length();
        vector<char> lword;

        for(int i=n-1; i>=0; i--){
            if(lword.size() >= 1 && s[i] == ' '){
                break;
            }
            else if(0 == lword.size() and s[i] == ' '){

            }
            else{
                lword.push_back(s[i]);
            }
        }

        return lword.size();
}

int main(){
    string s = {"b a "};
    cout << lengthOfLastWord(s) << endl;
    return 0;
}