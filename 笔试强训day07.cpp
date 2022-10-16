#include<bits/stdc++.h>

using namespace std;
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        if(A.size() % 2 != 0){
            return false;
        }
        stack<char>s;
        int index = 0;
        while(index < n){
            char ch = A[index++];
            if(isalpha(ch)){
                return false;
            }
            switch(ch){
                case '(':
                    s.push(ch);
                    break;
                case ')':
                    char t = s.top();
                    s.pop();
                    if(t != '('){
                        return false;
                    }
                    break;
            }
        }
        if(s.empty()){
            return true;
        }else{
            return false;
        }
    }
};
int getFibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n <= 2)
    {
        return 1;
    }
    int a = 1;
    int b = 1;
    int c;
    while (n > 2)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

int main()
{
    int n = 0;
    cin >> n;
    int num = 0;
    int i = 1;
    while ((num = getFibonacci(i)) <= n)
    {
        i++;
    }
    cout << min(abs(num - n), abs(n - getFibonacci(i - 1))) << endl;
    return 0;
}