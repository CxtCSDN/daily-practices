#define _CRT_SECURE_NO_WARNINGS 1
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct One {
    double d;
    char c;
    int i;
};
struct Two {
    char c;
    double d;
    int i;
};


int main()
{
    int n = 0;
    cin >> n;
    vector<int>nums;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;
        nums.push_back(tmp);
    }
    int sum = 0, ret = 0;
    for (int i = 0; i < n; i++) {
        sum = max(sum + nums[i], nums[i]);
        ret = max(sum, ret);
    }

    cout << ret << endl;
    return 0;
}