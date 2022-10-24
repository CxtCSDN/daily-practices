#include <bits/stdc++.h>
using namespace std;

int main()
{
    string cmd;
    getline(cin, cmd);
    vector<string> ret;
    int count = 0;
    int pos = 0, prePos = 0;
    while ((pos = cmd.find(' ', pos)) != string::npos)
    {
        count++;
        ret.push_back(cmd.substr(prePos, pos - prePos));
        pos++;
        prePos = pos;
        if (cmd[pos] == '"')
        {
            count++;
            prePos = ++pos;
            while (cmd[pos] != '"')
            {
                pos++;
            }
            ret.push_back(cmd.substr(prePos, pos - prePos));
            pos += 2;
            prePos = pos;
        }
    }
    if (prePos < cmd.size())
    {
        count++;
        ret.push_back(cmd.substr(prePos));
    }
    cout << count << endl;
    for (auto &val : ret)
    {
        cout << val << endl;
    }
    return 0;
}