#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string originalDigits(string s)
    {
        //记录每个字符的个数
        unordered_map<char, int> c;
        for (char ch : s)
        {
            ++c[ch];
        }
        //建立字母对应的数字映射
        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];

        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];
        //遍历建立升序返回
        string ans;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < cnt[i]; ++j)
            {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};
