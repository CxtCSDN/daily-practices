#include <bits/stdc++.h>
using namespace std;

// void getTriangle(vector<vector<int>> &nums)
// {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         nums[i].resize(i * 2 + 1, 1);
//     }
//     for (int i = 2; i < nums.size(); i++)
//     {
//         for (int j = 1; j < nums[i].size() - 1; j++)
//         {
//             if (j - 2 >= 0 && j < nums[i - 1].size())
//             {
//                 nums[i][j] = nums[i - 1][j - 2] + nums[i - 1][j - 1] + nums[i - 1][j];
//             }
//             else if (j - 2 < 0)
//             {
//                 nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
//             }
//             else if (j >= nums[i - 1].size())
//             {
//                 nums[i][j] = nums[i - 1][j - 2] + nums[i - 1][j - 1];
//             }
//         }
//     }
// }

// int getTriangle(int n)
// {
//     if (n <= 2)
//     {
//         return -1;
//     }
//     vector<int> first(3, 1), second;
//     int row = 3;
//     while (row <= n)
//     {
//         second.resize((row - 1) * 2 + 1, 1);
//         for (int i = 1; i <= second.size() / 2; i++)
//         {
//             if (i - 2 >= 0 && i < first.size() / 2)
//             {
//                 second[i] = first[i - 2] + first[i - 1] + first[i];
//             }
//             else if (i - 2 < 0)
//             {
//                 second[i] = first[i - 1] + first[i];
//             }
//             else if (i >= first.size() / 2)
//             {
//                 second[i] = first[i - 2] + first[i - 1];
//             }
//             if (row == n && second[i] % 2 == 0)
//             {
//                 return i + 1;
//             }
//         }
//         first = second;
//         row++;
//     }
//     return -1;
// }

int getTriangle(int n){
    if(n <= 2){
        return -1;
    }
    if(n % 2 == 1){
        return 2;
    }
    if(n % 4 == 0){
        return 3;
    }
    return 4;
}
int main()
{
    int n = 0;
    cin >> n;
    cout << getTriangle(n) << endl;

    return 0;
}