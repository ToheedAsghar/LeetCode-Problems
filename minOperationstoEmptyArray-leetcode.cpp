// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int minOperations(vector<int> &nums);
int minOperations(vector<int> &memo, int n);

int main()
{
    // 14,12,14,14,12,14,14,12,12,12,12,14,14,12,14,14,14,12,12
    // answer 7
    vector<int> nums = {3, 3};
    cout << minOperations(nums) << "\n";
    return 0;
}

int minOperations(vector<int> &memo, int n)
{
    if (n == 1)
    {
        return -1;
    }

    if (INT_MIN != memo[n])
    {
        return memo[n];
    }

    for (int i = 5; i <= n; i++)
    {
        memo[i] = 1 + min(memo[i - 2], memo[i - 3]);
    }
    return memo[n];
}
int minOperations(vector<int> &nums)
{
    if (nums.size() < 2)
    {
        return -1; // impossible
    }

    map<int, int> hashTable;
    for (int i = 0; i < nums.size(); i++)
    {
        hashTable[nums[i]]++;
    }

    int n = hashTable.begin()->second;
    for (const auto &pair : hashTable)
    {
        if (pair.second > n)
        {
            n = pair.second;
        }
    }

    vector<int> memo(n + 1, INT_MIN);
    if(n >= 4){
        memo[0] = 0;
        memo[4] = 2;
        memo[1] = -1;
        memo[3] = memo[2] = 1;
    }
    if(n >= 3){
        memo[3] = memo[2] = 1;
        memo[0] = 0;
        memo[1] = 1;
    }

    if(n >= 2){
        memo[1] = -1;
        memo[2] = 1;
        memo[0] = 0;
    }

    if(n >= 1){
        memo[1] = -1;
        memo[0] = 0;
    }
    

    int operations = 0;
    for (auto it : hashTable)
    {
        int t = minOperations(memo, it.second);
        if (-1 == t)
        {
            return -1;
        }
        operations += t;
    }
    return operations;
}
