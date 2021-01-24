#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define _for(i,a,b) for(int i=(a);i<(b);i++)

//P96.2
//按下图所示铁道进行车厢调度(注意, 两侧铁道均为单向行驶道, 火车调度站有一个用
//于调度的“栈道”), 火车调度站的入口处有n节硬座和软座车厢(分别用H和S表示)
//等待调度, 试编写算法, 输出对这n节车厢迸行调度的操作(即入栈或出栈操作)序列,
//以使所有的软座车厢都被调整到硬座车厢之前。

string Arrange(string sats) {

    stack<char> arr;
    string s;
    int j = 0;
    _for(i, 0, sats.size()) {
        if (sats[i] == 'S') {
            s += sats[i];
        }
        else {
            arr.push(sats[i]);
        }
    }
    while (!arr.empty()) {
        s += arr.top();
        arr.pop();
    }
    return s;
}

int main()
{
    string sats= "HSSSHHHSSHHHHHSSHHSSHSHSHSHS";
    cout << Arrange(sats) << endl;
    return 0;
}

