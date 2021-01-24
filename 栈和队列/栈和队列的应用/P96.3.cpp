#include <iostream>
#include <string>

using namespace std;

#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define MaxSize 30
//P96.3
//利用一个栈实现以下递归函数的非递归计算:
//            1                                          n = 0
//    Pn(x) = 2x                                         n = 1
//            2x * Pn-1(x) - 2(n - 1) * Pn-2(x)          n > 1

//直接用数组实现不是更方便 -> ->

double Calculate(int n,double x) {
    struct stack {
        int number;
        double value;
    }Sqstack[MaxSize];
    int top = -1, i;
    double f1 = 1, f2 = 2 * x;
    for (i = n; i >= 2; i--) {
        top++;
        Sqstack[top].number = i;
    }
    while (top >= 0) {
        Sqstack[top].value = 2 * x * f2 - 2 * (Sqstack[top].number - 1) * f1;
        f1 = f2;
        f2 = Sqstack[top].value;
        top--;
    }
    if (n == 0) {
        return f1;
    }
    return f2;
}

int main()
{
    cout << Calculate(6,3.14) << endl;
    return 0;
}

