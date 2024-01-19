// https://leetcode.com/problems/longest-increasing-subsequence/description
// Date: 5Jan2024
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int> memo(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    int t = memo[j] + 1;
                    memo[i] = max(t, memo[i]);
                }
            }
        }
        auto it = max_element(memo.begin(), memo.end());
        return *it;
    }

};

// 10,9,2,5,3,7,101,18         4
// 0,1,0,3,2,3                 4
// 7,7,7,7,7,7,7               1

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution solution;
    cout << solution.lengthOfLIS(nums) << '\n';
    return 0;
}

