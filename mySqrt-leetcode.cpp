// https://leetcode.com/problems/sqrtx/description/

#include <iostream>
#include <cmath>
using namespace std;

int mySqrt(int x);
int mySqrt(int n, int l, int r);

int main(){
    int n;
    cin >> n;

    cout << mySqrt(n) << endl;
    return 0;
}

int mySqrt(int x){
    if (0 == x || 1 == x){ // edge case
        return x;
    }
    else{
        return mySqrt(x, 0, x - 1);
    }
}

int mySqrt(int n, int l, int r){
    if (l > r){
        return r;
    }
    else
    {
        long long mid = ceil((r - l) / 2 + l);
        if (mid * mid == n){
            return mid;
        }
        if (mid * mid > n){
            return mySqrt(n, 0, mid - 1);
        }
        else{
            return mySqrt(n, mid + 1, r);
        }
    }
}
