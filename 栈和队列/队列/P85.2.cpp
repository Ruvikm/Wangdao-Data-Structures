#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//P85.2
//Q是一个队列, S是一个空栈, 实现将队列中的元素逆置的算法

//P85.2
void Reserve(stack<int>& S, queue<int>& Q) {
    while (!S.empty()) {
        int x = S.top();
        S.pop();
        Q.push(x);
    }

}
int main()
{
    stack<int> S;
    queue<int> Q;
    for (int i = 1; i <= 5; i++) {
        S.push(i);
    }
    Reserve(S, Q);
    for (int i = 1; i <= 5; i++) {
        int x = Q.front();
        Q.pop();
        cout << x << endl;
    }
    return 0;
}