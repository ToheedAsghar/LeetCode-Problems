// link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
#include <bits/stdc++.h>
using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit);
int dfs(vector<int>& startTime, vector<vector<int>> jobs, vector<int>& memo, int i);

// Naive Solution
class Solution {
public:
    int partition(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int low, int high){
        int pivot = startTime[high];
        int i = low;
        int j = low;
        while(j < high){
            if(startTime[j] <= pivot){
                swap(startTime[i], startTime[j]);
                swap(endTime[i], endTime[j]);
                swap(profit[i], profit[j]);
                ++j; ++i;
            }
            else{
                ++j;
            }
        }
        swap(startTime[i], startTime[high]);
        swap(endTime[i], endTime[high]);
        swap(profit[i], profit[high]);
        return i;
    }
    void quickSort(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int low, int high){
        if(low >= high){
            return;
        }
        int pivot = partition(startTime, endTime, profit, low, high);
        quickSort(startTime, endTime, profit, low, pivot-1);
        quickSort(startTime, endTime, profit, pivot+1, high);
    }
    int jobScheduling(vector<int> startTime, vector<int> endTime, vector<int> profit) {
        int n = startTime.size();
        quickSort(startTime, endTime, profit, 0, n-1);
        vector<int> memo(n, 0);
        memo[0] = profit[0];
        for(int i=1; i<n; i++){
            int temp = profit[i];
            for(int j=0; j<i; j++){
                if(startTime[i] >= endTime[j]){
                    temp = max(temp, profit[i]+memo[j]);
                }
            }
            memo[i] = temp;
        }
        return *(max_element(memo.begin(),memo.end()));
    }
};

int main(){
    vector<int> startTime = {24,24,7,2,1,13,6,14,18,24}, endTime = {27,27,20,7,14,22,20,24,19,27}, profit = {6,1,4,2,3,6,5,6,9,8};
    cout << jobScheduling(startTime, endTime, profit) << '\n';
    return 0;
}

// {1,2,3,4,6}, {3,5,10,6,9}, {20,20,100,70,60} = 150
// {6,15,7,11,1,3,16,2}, {19,18,19,16,10,8,19,8}, {2,9,1,19,5,7,3,19} = 41
// {24,24,7,2,1,13,6,14,18,24}, {27,27,20,7,14,22,20,24,19,27}, {6,1,4,2,3,6,5,6,9,8} = 20

int dfs(vector<int>& startTime, vector<vector<int>> jobs, vector<int>& memo, int i){
    if(i >= memo.size()){
        return 0;
    }
    if(-1 == memo[i]){
        int index = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();
        int t = jobs[i][2] + dfs(startTime, jobs, memo, index);
        int nt = dfs(startTime, jobs, memo, i+1);
        memo[i] = max(t, nt);
    }

    return memo[i];
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();

    vector<vector<int>> jobs;
    for(int i=0; i<n; i++){
        jobs.push_back({startTime[i],endTime[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end());
    sort(startTime.begin(), startTime.end());

    vector<int> memo(n, -1);
    return dfs(startTime, jobs, memo, 0);
}