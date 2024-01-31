// 739 https://leetcode.com/problems/daily-temperatures/
#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &tmp)
{
    stack<pair<int, int>> st;
    int n = tmp.size();
    vector<int> rec(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first < tmp[i])
        {
            int ind = st.top().second;
            rec[ind] = i - ind;
            st.pop();
        }
        st.push({tmp[i], i});
    }
    return rec;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ret = dailyTemperatures(temperatures);
    for (const auto &it : ret)
    {
        cout << it << ' ';
    }
    cout << '\n';
    return 0;
}