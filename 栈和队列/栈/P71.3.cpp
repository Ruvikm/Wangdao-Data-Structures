#include <iostream>
#include <vector>
using namespace std;

//P71.3
//假设以I和O分别表示入栈和出栈操作。栈的初态和终态均为空, 入栈和出栈的操作序
//列可表示为仅由I和O组成的序列, 可以操作的序列称为合法序列, 否则称为非法序列
//)下面所示的序列中哪些是合法的
//A.IOlIOIOO 合法
//B.IOOIOlO
//C.IIIOIOIO
//D.IIIOOIOO  合法
//2)通过对1)的分析, 写出一个算法, 判定所给的操作序列是否合法。若合法, 返回true
//否则返回 false(假定被判定的操作序列已存入一维数组中)


#define _for(i,a,b) for(int i=(a);i<(b);i++)

//P71.3
bool Legal(vector<char> str) {
	int size = 0;
	_for(i, 0, str.size()) {
		if (str[i] == 'I') {
			size++;
		}
		if (str[i] == 'O') {
			size--;
		}
		if (size < 0)
			return false;
	}
	if (!size)
		return true;
}

int main()
{
	vector<char> str1 = { 'I','O','I','I','O','I','O','O' };
	vector<char> str2 = { 'I','O','O','I','O','I','I','O' };
	cout << Legal(str1) << endl;
	return 0;

}

