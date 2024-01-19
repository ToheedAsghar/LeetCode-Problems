// https://leetcode.com/problems/word-pattern/description/
#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s);
bool checkInHash(unordered_map<string, char> &h, char &s);

int main()
{
    cout << wordPattern("abba", "dog cat cat dog");
    return 0;
}

bool checkInHash(const unordered_map<string, char> &h, const char &s)
{
    for (const auto &pair : h)
    {
        if (s == pair.second)
        {
            return true;
        }
    }
    return false;
}

bool wordPattern(string pattern, string s)
{
    int n = s.size();
    vector<string> in;
    string temp;
    // pushing the string into vector
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            in.push_back(temp);
            temp.clear();
        }
        else
            temp += s[i];
    }
    in.push_back(temp);

    // special case
    // pattern = "jquery" s = "jquery"
    if (pattern.size() != in.size())
    {
        return false;
    }

    unordered_map<string, char> hashMap;
    n = in.size();
    for (int i = 0; i < n; i++)
    {
        if (hashMap.find(in[i]) == hashMap.end())
        {
            if (!checkInHash(hashMap, pattern[i]))
                hashMap[in[i]] = pattern[i];
            else
                return false;
        }
        else
        {
            if (hashMap[in[i]] != pattern[i])
            {
                return false;
            }
        }
    }

    return true;
}