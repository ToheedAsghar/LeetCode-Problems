// https://leetcode.com/problems/longest-common-prefix/description/
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs);

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs);
    return 0;
}

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    int m = strs[0].size();

    string res;                         // return value
    bool flag = true;

    for (int i = 0; i < m; i++)         // for iterating the cols
    {
        for (int j = 1; j < n; j++)     // for iterating the rows
        {
            if (i >= strs[j].size() or strs[j][i] != strs[0][i])
            {
                flag = false;
                break;
            }
        }
        if (false == flag)
            break;
        else
            res.push_back(strs[0][i]);
    }
    return res;
}