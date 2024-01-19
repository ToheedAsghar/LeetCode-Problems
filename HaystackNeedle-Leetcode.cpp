// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
#include <iostream>
#include <vector>
using namespace std;

int strStr(string haystack, string needle);

int main(){
    string haystack, needle;
    cin >> haystack >> needle;

    cout << strStr(haystack, needle) << endl;
    return 0;
}

int strStr(string haystack, string needle) {
    if(needle.size() > haystack.size()){
        return -1;
    }
    int i, j=0, retVal = -1;
    for(i=0; i<haystack.size(); i++){
        if(haystack[i] == needle[j]){
            string temp = haystack.substr(i, needle.size());
            if(needle == temp){
                retVal = i;
                break;
            }
        }
    }
    return retVal;
}