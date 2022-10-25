#include <bits/stdc++.h>
using namespace std;

// class Base
// {
// public:
//     Base(int j) : i(j) {}
//     virtual ~Base() {}
//     void func1()
//     {
//         i *= 10;
//         func2();//多态调用Child的func2()
//     }
//     int getValue()
//     {
//         return i;
//     }
// protected:
//     virtual void func2()
//     {
//         i++;
//     }
// protected:
//     int i;
// };
// class Child : public Base
// {
// public:
//     Child(int j) : Base(j) {}
//     void func1()
//     {
//         i *= 100;
//         func2();
//     }
// protected:
//     void func2()
//     {
//         i += 2;
//     }
// };
// int main()
// {
//     Base *pb = new Child(1);
//     pb->func1();//Base里的func1()
//     cout << pb->getValue() << endl;
//     delete pb;
// }

// class A
// {
// public:
//     void test(float a) { cout << "1"; }
// };
// class B : public A
// {
// public:
//     void test(int b) { cout << "2"; }
// };
// int main()
// {
//     A *a = new A;
//     B *b = new B;
//     a = b;
//     a->test(1.1);
// }


// class B0
// {
// public:
//     virtual void display()
//     {
//         cout << "B0::display0" << endl;
//     }
// };
// class B1 : public B0
// {
// public:
//     void display() { cout << "B1::display0" << endl; }
// };
// class D1 : public B1
// {
// public:
//     void display()
//     {
//         cout << "D1::display0" << endl;
//     }
// };
// void fun(B0 ptr)
// {
//     ptr.display();
// }
// int main()
// {
//     B0 b0;
//     B1 b1;
//     D1 d1;
//     fun(b0);
//     fun(b1);
//     fun(d1);
// }

// static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// int main()
// {
//     int year, month, day;
//     cin >> year >> month >> day;
//     int count = 0;
//     month -= 1;
//     while (month)
//     {
//         if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0 && month == 2)
//         {
//             count += 29;
//         }
//         else
//         {
//             count += days[month];
//         }
//         month--;
//     }
//     count += day;
//     cout << count << endl;
//     return 0;
// }

int get(vector<int> arr, int n, int pos, int add, int multi)
{
    // pos：访问到的位置   add：加到了多少  multi; 乘到了多少
    int count = 0;
    for (int i = pos; i < n; i++)
    {
        add += arr[i];
        multi *= arr[i];

        if (add > multi) //假如add > multi ， 该条件满足，并且往下面找满足的条件
            count += 1 + get(arr, n, i + 1, add, multi);
        else if (arr[i] == 1) //假如arr[i]==1 ，则该条件无效， 向后面找寻有效条件
            count += get(arr, n, i + 1, add, multi);
        else
            break;

        add -= arr[i];
        multi /= arr[i];
        while (i < n - 1 && arr[i] == arr[i + 1]) //将相同项移出，不再假如循环
            i++;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end()); //先将数组排序
    cout << get(nums, n, 0, 0, 1) << endl;

    return 0;
}