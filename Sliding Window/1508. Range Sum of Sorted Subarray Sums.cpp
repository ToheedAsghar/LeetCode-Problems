#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;


class Solution {
public:

    const int MOD = 1e9+7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int size = n * (n + 1) / 2;
        vector<int > subArraySums;
        
        int currSum = 0;
        for(int i=0; i<n; i++){
            currSum = 0;
            for(int j=i; j<n; j++){
                currSum = (currSum + nums[j]);
                subArraySums.push_back(currSum);
            }
        }

        assert(size == subArraySums.size());

        sort(subArraySums.begin(), subArraySums.end());

        int retSum = 0;
        for(int i = left - 1; i < right; i++){
            retSum = (retSum + subArraySums[i]) % MOD;
        }

        return (int) retSum;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4};

    Solution sol;
    int retSum = sol.rangeSum(nums, 4, 1, 5);
    cout << retSum << endl;
    return 0;
}
