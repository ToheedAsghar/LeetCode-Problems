#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> result;

        bool flag = true;
        int i = 0;
        int j = 0;
        int k = 0;
        int cnt = 0;

        while (cnt != n * m)
        {
            // move forward
            while (j < m - k)
            {
                result.push_back(matrix[i][j]);
                cnt++;
                j++;
            }

            if(cnt == n*m){
                break;
            }

            j -= 1;
            i += 1;

            // move downward
            while (i < n - k)
            {
                result.push_back(matrix[i][j]);
                cnt++;
                i++;
            }

            if(cnt == n*m){
                break;
            }

            i -= 1;
            j -= 1;

            // move backward
            while (j >= k)
            {
                result.push_back(matrix[i][j]);
                j -= 1;
                cnt++;
            }

            if(cnt == n*m){
                break;
            }

            j += 1;
            i -= 1;

            // move upward
            while (i > k)
            {
                result.push_back(matrix[i][j]);
                i -= 1;
                cnt++;
            }

            i += 1;
            j += 1;

            if(cnt == n*m){
                break;
            }

            k += 1;
        }

        return result;
    }
};

int main()
{
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    auto sol = Solution();
    auto result = sol.spiralOrder(matrix);

    for(const auto& it: result){
        cout << it << ' ';
    } cout << "\n";

    return 0;
}
