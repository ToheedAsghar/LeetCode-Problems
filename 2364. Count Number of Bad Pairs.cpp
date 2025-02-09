class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        unordered_map<int, int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            mp[nums[i]-i]++;
        }

        long long int gp = 0;

        for(const auto& it: mp){
            if(it.second > 1) gp += static_cast<long long>(it.second) * (it.second-1) / 2;
        }

        return static_cast<long long>(n) * (n-1) / 2 - gp;
    }
};
