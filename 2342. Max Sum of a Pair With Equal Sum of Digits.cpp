// #include <bits/stdc++.h>
// using namespace std;

long long int countDigits(int num){
    if(0 == num or 1 == num){
        return num;
    }
    long long int digitSum = 0;
    while(num != 0){
        digitSum += num%10;
        num /= 10;
    }

    return digitSum;
}

class Solution {
public:
    long long int maximumSum(vector<int>& nums) {
        unordered_map<long long int, vector<int>> mp;

        for(const auto& it: nums){
            mp[countDigits(it)].push_back(it);
        }

        long long int maxSum = INT_MIN;
        for(const auto& pair: mp){
            auto arr = pair.second;
            int n = arr.size();
            if(n >= 2){
                sort(arr.begin(), arr.end());
                maxSum = max(maxSum, static_cast<long long int>(arr[n-1]) + arr[n-2]);
            }
        }

        return (maxSum!= INT_MIN)? maxSum : -1;
    }
};


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int n; cin >> n;
//     vector<int> arr (n, 0);

//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }

//     auto sol = Solution();
//     cout << sol.maximumSum(arr) << '\n';
//     return 0;
// }
