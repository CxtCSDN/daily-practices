#include <bits/stdc++.h>
using namespace std;

bool strMatch(const char *res, const char *des)
{
    if (*res == '\0' && *des == '\0')
    {
        return true;
    }
    if (*res == '\0' || *des == '\0')
    {
        return false;
    }
    if (*res == '?' && !(isdigit(*des) || isalpha(*des)))
        return false;
    if (*res == '?')
    {
        return strMatch(res + 1, des + 1);
    }
    else if (*res == '*')
    {
        return strMatch(res + 1, des) || strMatch(res + 1, des + 1) || strMatch(res, des + 1);
    }
    else if (*res == *des)
    {
        return strMatch(res + 1, des + 1);
    }
    return false;
}
bool isMatch(string p, string s)
{
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i - 1] == '*')
        {
            dp[0][i] = true;
        }
        else
        {
            break;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            }
            else if (p[j - 1] == '?' && (isdigit(s[i - 1]) || isalpha(s[i - 1])) || s[i - 1] == p[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string res, des;
    getline(cin, res);
    getline(cin, des);
    for (int i = 0; i < res.size(); i++)
    {
        if (isalpha(res[i]))
        {
            res[i] = tolower(res[i]);
        }
    }
    for (int i = 0; i < des.size(); i++)
    {
        if (isalpha(des[i]))
        {
            des[i] = tolower(des[i]);
        }
    }
    bool ret = strMatch(res.c_str(), des.c_str());
    if (ret)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}