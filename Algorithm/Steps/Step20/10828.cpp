#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
	int length;
	int arr[10000];

public:
	int size;
public:
	Stack() : length(5), size(0) {}

	int Size() {
		return size;
	}

	void Push(int element) {
		arr[size++] = element;
	}

	int Pop() {
		if (!size) {
			return -1;
		}
		return arr[--size];
	}
	
	int Empty() {
		if (!size) {
			return 1;
		}
		return 0;
	}

	int Top() {
		if (!size) {
			return -1;
		}
		return arr[size - 1];
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int orderCnt;

	Stack stk;
	string str;

	cin >> orderCnt;

	while(orderCnt--){
		cin >> str;

		if (!str.compare("push")) { // push ÀÌ¸י
			int element;
			cin >> element;
			
			stk.Push(element);
		}
		else if (!str.compare("top")) {
			cout << stk.Top() << '\n';
		}
		else if (!str.compare("size")) {
			cout << stk.Size() << '\n';
		}
		else if (!str.compare("pop")) {
			cout << stk.Pop() << '\n';
		}
		else if (!str.compare("empty")) {
			cout << stk.Empty() << '\n';
		}
	}

	return 0;
}