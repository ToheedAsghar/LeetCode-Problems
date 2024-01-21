// link: https://leetcode.com/problems/house-robber/
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums);

int main(){
    vector<int> arr = {2,7,9,3,1};
    cout << rob(arr);
}

int robDP(vector<int>& nums, vector<int>& memo, int index){
    int n = memo.size();
    if(index >= n){             // base case
        return INT_MIN;
    }

    if(index == n-1 ||  index == n-2){
        return memo[index] = nums[index];
    }

    if(-1 == memo[index]){
        int maxValue = 0;
        for(int i=index+2; i<n; i++){
            memo[index] = max(memo[index], nums[index] + robDP(nums, memo, i));
        }
    }
    return memo[index];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> memo(n, -1);
    int retVal1 = robDP(nums, memo, 0);
    int retVal2 = robDP(nums, memo, 1);

    return max(retVal1, retVal2);
}

