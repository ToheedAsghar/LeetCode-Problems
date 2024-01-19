// link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findMatrix(vector<int> &nums);

int main(){
    vector<int> vec = {1,3,4,1,2,3,1};
    vector<vector<int>> twoD = findMatrix(vec);

    for(auto &in: twoD){
        for(auto& it: in){
            cout << it << " ";
        } cout << endl;
    }

    return 0;
}
vector<vector<int>> findMatrix(vector<int> &nums)
{
    vector<int> orderOfInsertion;  // To store the order of insertion
    unordered_map<int, int> hashTable;

    for (int& element : nums) {
        if (hashTable.find(element) == hashTable.end()) {
            orderOfInsertion.push_back(element);
        }
        hashTable[element]++;
    }

    // printing the hashtable
    // for(auto it: orderOfInsertion){
    //     cout << it << " " << hashTable[it] << endl;
    // }

    vector<vector<int>> vec;
    bool flag = true;
    while (flag)
    {
        vector<int> temp;
        for (int it = 0; it < orderOfInsertion.size(); )
        {
            int key = orderOfInsertion[it];
            int value = hashTable[key];

            if (value != 0)
            {
                temp.push_back(key);
                hashTable[key]--;
                it++;
            }
            else{
                hashTable.erase(key);
                orderOfInsertion.erase(orderOfInsertion.begin() + it);
            }
        }
        if(hashTable.size() == 0){
            break;
        }
        vec.push_back(temp);
    }

    return vec;
}