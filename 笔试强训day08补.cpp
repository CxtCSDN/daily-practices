#include <bits/stdc++.h>
using namespace std;
bool isLexicographically(vector<string> strs)
{
    vector<string> tmp(strs.begin(), strs.end());
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < strs.size(); i++)
    {
        if (strs[i] != tmp[i])
        {
            return false;
        }
    }
    return true;
}
bool isLengths(vector<string> strs)
{
    for (int i = 1; i < strs.size(); i++)
    {
        if (strs[i - 1].size() > strs[i].size())
            return false;
    }
    return true;
}
int main()
{
    int n = 0;
    vector<string> strs;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        strs.push_back(tmp);
    }
    if (isLengths(strs) && isLexicographically(strs))
    {
        cout << "both" << endl;
    }
    else if (isLengths(strs))
    {
        cout << "lengths" << endl;
    }
    else if (isLexicographically(strs))
    {
        cout << "lexicographically" << endl;
    }
    else
    {
        cout << "none" << endl;
    }
    return 0;
}