// https://leetcode.com/problems/determine-if-two-strings-are-close/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        bool retVal;
        if(n1 != n2){
            retVal = false;
        } else {
            unordered_map<char, int> cnt;
            vector<char> keys1, keys2;
            for(const auto& it: word1){
                cnt[it]++;
            }
            vector<int> arr1, arr2;
            for(const auto pair: cnt){
                arr1.push_back(pair.second);
                keys1.push_back(pair.first);
            }
            cnt.clear();
            for(const auto& it: word2){
                cnt[it]++;
            }
            for(const auto pair: cnt){
                keys2.push_back(pair.first);
                arr2.push_back(pair.second);
            }

            sort(keys1.begin(), keys1.end());
            sort(keys2.begin(), keys2.end());
            sort(arr1.begin(), arr1.end());
            sort(arr2.begin(), arr2.end());

            if(arr1.size() != arr2.size()){
                retVal = false;
            }
            else{

                int n = arr1.size();
                for(int i = 0; i<n; i++){
                    if(keys1[i] != keys2[i]){
                        return false;
                    }
                }

                for(int i=0; i<n; i++){
                    if(arr1[i] != arr2[i]){
                        retVal = false;
                        break;
                    }else{
                        retVal = true;
                    }
                }
            }
        }
        return retVal;
    }
};

int main(){
    Solution sol;
    cout << sol.closeStrings("uau", "ssx");
    return 0;
}