// https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    return false;
}
bool halvesAreAlike(string s)
{
    int c1 = 0, c2 = 0;
    int mid = s.size() / 2;
    for (int i = 0; i < mid; i++)
    {
        if (isVowel(s[i]))
        {
            c1++;
        }
    }
    for (int i = mid; i < s.size(); i++)
    {
        if (isVowel(s[i]))
        {
            c2++;
        }
    }

    return c1 == c2;
}

int main()
{
    cout << halvesAreAlike("textbook") << endl;
    return 0;
}