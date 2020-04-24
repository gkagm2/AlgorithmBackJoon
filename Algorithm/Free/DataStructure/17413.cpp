#include <iostream>
#include <stack>
using namespace std;

inline int Length(char word[]) {
	int cnt = 0;
	while (word[cnt] != '\0') {
		++cnt;
	}
	return cnt;
}

inline void PrintStack(stack<char> &stk) {
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
}
char word[100001];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack<char> stk;

	cin.getline(word, 100001);

	int cnt = 0;
	bool isTag = false;
	while (word[cnt] != '\0') {

		if (word[cnt] == ' ' && isTag == false) {
			PrintStack(stk);
			cout << ' ';
		}
		else if (word[cnt] == '<') {
			PrintStack(stk);
			cout << '<';
			isTag = true;
		}
		else if (word[cnt] == '>') {
			cout << '>';
			isTag = false;
		}
		else if(isTag == true){
			cout << word[cnt];
		}
		else {
			stk.push(word[cnt]);
		}
		++cnt;
	}
	PrintStack(stk);

	return 0;
}