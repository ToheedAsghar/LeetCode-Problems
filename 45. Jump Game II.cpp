class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        assert(n>=1);

        vector<int> dp (n, n+1);
        dp[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            int m = i + nums[i];
            if(m >= n-1) { dp[i] = 1; }

            for(int j = i; j <= m and j < n; j++){
                dp[i] = min(dp[i], 1 + dp[j]);
            }

        }

        return dp[0] < n ? dp[0] : -1;
    }

};
