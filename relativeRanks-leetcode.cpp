// https://leetcode.com/problems/relative-ranks/description/ 

#include <bits/stdc++.h>
using namespace std;

// Final Solution
vector<string> findRelativeRanks(vector<int>& score);

// Initial Solution
int binarySearch(vector<int> array, int x, int low, int high);
void QuickSortValues(vector<pair<pair<int, int>, string>>& scores, int l, int u);
int partitionValues(vector<pair<pair<int, int>, string>>& scores, int l, int u);
vector<string> findRelativeRanksI(vector<int>& score);

int main(){
    vector<int> arr = {10, 2, 8, 1, 9};
    vector<string> str = findRelativeRanks(arr);

    for(auto it: str){
        cout << it <<  " ";
    } cout << endl;

    return 0;
}

vector<string> findRelativeRanks(vector<int>& score) {

    int n = score.size();
    vector<pair<int, int>> sc(n);

    for(int i=0; i<n; i++){
        sc[i].first = score[i];
        sc[i].second = i;
    }

    sort(sc.rbegin(), sc.rend());

    // displaying the sc
    for(auto it: sc){
        cout << it.first << " " << it.second << endl;
    } cout << endl;

    vector<string> retVec (n);
    for(int i=0; i<n; i++){
        if(0 == i){
            retVec[sc[i].second] = "Gold Medal";
        }
        else if(1 == i){
            retVec[sc[i].second] = "Silver Medal";
        }
        else if(2 == i){
            retVec[sc[i].second] = "Bronze Medal";
        }
        else{
            retVec[sc[i].second] = to_string(i+1); 
        }
    }
    return retVec;
}

int binarySearch(vector<int> array, int x, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If found at mid, then return it
        if (array[mid] == x)
            return mid;

        // Search the left half
        if (array[mid] < x)
            return binarySearch(array, x, low, mid - 1);

        // Search the right half
        return binarySearch(array, x, mid + 1, high);
    }
    return -1;
}
void QuickSortValues(vector<pair<pair<int, int>, string>>& scores, int l, int u) {
    if (l < u) {
        int pivot = partitionValues(scores, l, u);
        QuickSortValues(scores, l, pivot - 1);
        QuickSortValues(scores, pivot + 1, u);
    }
}
int partitionValues(vector<pair<pair<int, int>, string>>& scores, int l, int u) {
    int pivot = scores[u].first.second;
    int i = l - 1;
    for (int j = l; j <= u; j++) {
        if (scores[j].first.second > pivot) {
            ++i;
            swap(scores[j].first.second, scores[i].first.second);
            swap(scores[j].first.first, scores[i].first.first);
        }
    }
    swap(scores[i + 1].first.second, scores[u].first.second);
    swap(scores[i + 1].first.first, scores[u].first.first);
    return i + 1;
}
vector<string> findRelativeRanksI(vector<int>& score) {
    vector<pair<pair<int, int>, string>> scores(score.size());
    for (int i = 0; i < score.size(); i++) {
        scores[i].first.first = i;
        scores[i].first.second = score[i];
    }

    // sorting based on values
    QuickSortValues(scores, 0, scores.size() - 1);

    // assinging special case valeus
    if (0 < score.size()) {
        scores[0].second = "Gold Medal";
    }
    if (1 < score.size()) {
        scores[1].second = "Silver Medal";
    }
    if (2 < score.size()) {
        scores[2].second = "Bronze Medal";
    }

    int n = scores.size();
    for (int i = 3; i < n; i++) {
        scores[i].second = to_string(i + 1);
    }

    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = scores[i].first.second;
    }

    vector<string> retVec(n);
    for (int i = 0; i < n; i++) {
        int index = binarySearch(temp, score[i], 0, n-1 );
        if(-1 != index)
            retVec[i] = scores[index].second;
    }

    return retVec;
}