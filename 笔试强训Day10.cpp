#include <bits/stdc++.h>
using namespace std;
class Test
{
public:
    static int count;
    Test()
    {
        count++;
    }
    Test(int n){
        count++;
    }
    void foo()
    {
        delete this;
    }
};
int Test::count = 0;
int main()
{
    //Test(*pT)[3];
    // Test a(3), b(5), c[3], *p[2] = {&a, &b};
    Test a(), b(), c[3], *p[2] = {&a, &b};

    cout << Test::count << endl;
    return 0;
}