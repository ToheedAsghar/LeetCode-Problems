class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        assert(n >= 1);

        if(1 == n) { return true; }

        vector<bool> dp (n, 0);
        for(int i=n-2; i>=0; i--){
            int m = i + nums[i];
            for(int j = i; j <= m and j < n; j++){
                if(dp[j] == true or j+nums[j] >= n-1){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
