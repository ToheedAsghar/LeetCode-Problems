// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int n = nums.size();    // n is a multiple of 3
    
    vector<vector<int>> ret;

    // sorting the array
    sort(nums.begin(), nums.end());

    // 1 1 3 3 4 5 7 8 9
    for(int i=0; i<n ;i+=3){
        if(abs(nums[i] - nums[i+2]) <= k){
            ret.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        else{
            return {};
        }
    }
    return ret;
}

int main(){
    // 1,3,3,2,7,3
    // 1,3,4,8,7,9,3,5,1
    vector<int> nums = {1,3,3,2,7,3};
    for(const auto& row: divideArray(nums, 2)){
        for(const auto& ele: row){
            cout << ele << ' ';
        } cout << '\n';
    }
    return 0;
}