// https://leetcode.com/problems/third-maximum-number/description/
#include <bits/stdc++.h>
using namespace std;

int thirdMaxI(vector<int>& nums); // efficient solution
int thirdMaxII(vector<int>& nums);  // my solution

int main(){
}

int thirdMaxII(vector<int>& nums) {
        set<int, greater<int>> s;
        int n = nums.size();
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }

        n = s.size();
        vector<int> temp;
        for(auto i: s){
            temp.push_back(i);
        }
        if(n < 3){
            return temp[0];
        }
        else{
            return temp[2];
        }
}

int thirdMaxI(vector<int>& nums) {
        set<int> nums_set(nums.begin(), nums.end());
        if (nums_set.size() < 3){
            return *nums_set.rbegin();
        }
        auto it = nums_set.rbegin();
        advance(it, 2);
        return *it;
}