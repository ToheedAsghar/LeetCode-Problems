// link: https://leetcode.com/problems/house-robber/
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums);

int main(){
    vector<int> arr = {2,7,9,3,1};
    cout << rob(arr);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> memo(n, -1);

    function<int(int)> robDP = [&](int index) -> int { // using lamda function
        if (index >= n) {
            return INT_MIN;
        }

        if (index == n - 1 || index == n - 2) {
            return memo[index] = nums[index];
        }

        if (memo[index] == -1) {
            int maxValue = 0;
            for (int i = index + 2; i < n; i++) {
                memo[index] = max(memo[index], nums[index] + robDP(i));
            }
        }
        return memo[index];
    };

    int retVal1 = robDP(0);
    int retVal2 = robDP(1);

    return max(retVal1, retVal2);
}

