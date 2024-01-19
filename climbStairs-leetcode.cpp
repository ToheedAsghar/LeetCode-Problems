// https://leetcode.com/problems/climbing-stairs/description/
#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n);
int climbStairs(vector<int>& steps, int n);

int main(){
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}

int climbStairs(int n){
    if(0 == n){
        return 0;
    }
   vector<int> steps(46, -1);
   return climbStairs(steps, n);
}
int climbStairs(vector<int>& steps, int n){
     // base case
    if(0 == n || 1 == n){
        return 1;
    }

    if(-1 != steps[n]){
        return steps[n];
    }
    else{
        steps[n] = climbStairs(steps, n-1) + climbStairs(steps, n-2);
    }

    return steps[n];
}