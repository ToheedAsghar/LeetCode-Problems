// TC: O(N LOG N )

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp;

        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        bool flag = false;
        for(const auto& it: mp){
            int m = it.second.size();
            for(int i=0; i<m-1; i++){
                if(abs(it.second[i] - it.second[i+1]) <= k) flag = true;

                if (flag) break;
            }

            if(flag) break;
        }

        return flag;
    }
};
