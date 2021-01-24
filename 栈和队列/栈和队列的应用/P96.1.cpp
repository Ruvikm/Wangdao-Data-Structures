#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define _for(i,a,b) for(int i=(a);i<(b);i++)

void Bracket_Pairing() {

//	test:  "a+{[b*(c-d)]*e+f/(g-h)}*I";
//	test:  "a+{[b*(c-d)]]*e+f/(g-h)}*I)";

	string s;
	getline(cin, s);
	stack<char> bracket;
	_for(i, 0, s.size()) {
		if (s[i] == '(' || s[i] == '{' || (s[i] == '[')) {
			bracket.push(s[i]);
		}
		if (s[i] == ')' || s[i] == '}' || (s[i] == ']')) {

			char Parentheses = bracket.top();
			switch (Parentheses)
			{
				case '(': {
					if (s[i] == ')') {
						bracket.pop();
						break;
					}
				}
				case '[': {
					if (s[i] == ']') {
						bracket.pop();
						break;
					}
				}
				case '{': {
					if (s[i] == '}') {
						bracket.pop();
						break;
					}
				}
				default: {
					cout << "匹配失败!" << endl;
					return;
				}
			}
		}
	}
	if (bracket.empty()) {
		cout << "匹配成功！" << endl;
	}
	return;
}
int main()
{
	Bracket_Pairing();
	return 0;
}

