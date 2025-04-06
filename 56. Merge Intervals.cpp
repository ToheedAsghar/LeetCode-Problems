#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
  sort(intervals.begin(), intervals.end());

  vector<vector<int>> mergedIntervals;
  int n = intervals.size();

  assert(n >= 1);

  int i = 0;
  while (i < n)
  {
    int st = intervals[i][0];
    int end = intervals[i][1];

    int j = i + 1;
    while (j < n)
    {
      if (intervals[j][0] <= end)
      {
        end = max(intervals[j][1], end);
        j++;
      }
      else
      {
        break;
      }
    }

    mergedIntervals.push_back({st, end});
    i = j;
  }
  return mergedIntervals;
}

int main()
{
  // vector<vector<int>> arr = {
  //   {1,3}, {2,6}, {8, 10}, {15, 18}
  // };

  vector<vector<int>> arr = {
    {{1, 4}, {2, 3}}
  };
  auto mergedIntervals = merge(arr);

  for(const auto& it: mergedIntervals){
    cout << it[0] << " " << it[1] << "\n";
  } cout << "\n";

  return 0;
}
