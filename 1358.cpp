// #include <bits/stdc++.h>
// using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
    int n = s.size();
    int a = 0, b = 0, c = 0;
    int cnt = 0;
    int i = 0, j = 0;

    while(i < n - 2){
        while(j <= n){
            if(a >= 1 and b >= 1 and c >= 1){
                cnt += (n - j + 1);
                break;
            } else {
                if(s[j] == 'a') a++;
                else if(s[j] == 'b') b++;
                else c++;
                
                j++;
            }
        }

        if(s[i] == 'a') a--;
        else if(s[i] == 'b') b--;
        else c--;

        i += 1;
    }
    return cnt;
}
};



// int main(){
//     string s; cin >> s;
//     cout << numberOfSubstrings(s) << "\n";
// }
