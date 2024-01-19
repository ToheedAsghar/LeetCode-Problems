// https://leetcode.com/problems/sort-colors/
#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums); // using Dutch nation algorithm
void sortColorsI(vector<int>& nums);

int main(){
    vector<int> arr = { 2,0,2,1,1,0 };
    for (auto i : arr) {
        cout << i << " ";
    } cout << endl;
    sortColors(arr);
    for (auto i : arr) {
        cout << i << " ";
    } cout << endl;

	return 0;
}

// using Dutch Nation Algorithm
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;

    while(mid <= high){
        if(0 == nums[mid]){
            swap(nums[mid], nums[low]);
            ++low;
            ++mid;
        }
        else if(1 == nums[mid]){
            ++mid;
        }
        else{
            swap(nums[mid], nums[high--]);
        }
    }        
}

void sortColorsI(vector<int>& nums) {
    int r = 0, w = 0, b = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (0 == nums[i]) {
            ++r;
        }
        else if (1 == nums[i]) {
            ++w;
        }
        else {
            ++b;
        }
    }

    int i = 0;
    while (i < n && i < r) {
        nums[i++] = 0;
    }

    int j = 0;
    while (i < n && j < w) {
        nums[i++] = 1;
        ++j;
    }
    
    j = 0;
    while (i < n && j < b) {
        nums[i++] = 2;
        ++j;
    }
}