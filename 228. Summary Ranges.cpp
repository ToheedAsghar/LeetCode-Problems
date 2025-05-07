#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const double EPS = 1e-9;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> res;
            int i = 0;
            int n = nums.size();
    
            if(0 == n) return {};
            if(1 == n){
                return vector<string> ({to_string(nums[0])});
            }
    
            int st = i++;
            int end = st;
            while(i < n){
                if(nums[end] + 1 != nums[i]){
                    string range = ((end == st)? to_string(nums[st]) : (to_string(nums[st]) + "->" + to_string(nums[end])));
                    res.push_back(range);
                    st = i;
                }
                end = i++;
            }

            string range;
            if(nums[n-1] == nums[n-2] + 1){
                range = to_string(nums[st]) + "->" + to_string(nums[end]);
            } else{
                range = to_string(nums[end]);
            }
    
            res.push_back(range);
            return res;
        }
    };

int main() {
    fastIO();
    
    auto sol = Solution();
    vector<int> nums = {0,2,3,4,6,8,9};

    auto res = sol.summaryRanges(nums);

    for(const auto& it: res){
        cout << it << " ";
    } cout << "\n";
    
    return 0;
}
