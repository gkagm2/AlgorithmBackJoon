// list로 구현 시 20984KB, 72ms, stack으로 구현 시 메모리 10배 이상 줄임.
#include <iostream>
#include <list>
#include <string>
using namespace std;

inline void print(list<char>& editor) {
	auto editorBegin = editor.begin();
	auto editorEnd = editor.end();
	for (auto i = editorBegin; i != editorEnd; ++i) {
		cout << *i;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	list<char> editor;
	string sInput;

	getline(cin, sInput);
	for (int i = 0; i < sInput.size(); ++i) {
		editor.push_back(sInput[i]);
	}
	int commendCnt;
	cin >> commendCnt;
	cin.ignore();
	// current cursor set
	auto cursorItor = editor.end();

	while (commendCnt--) {
		string commend;
		getline(cin, commend);

		if (commend[0] == 'L') {
			if (cursorItor != editor.begin())
				--cursorItor;
		}
		else if (commend[0] == 'D') {
			if (cursorItor != editor.end())
				++cursorItor;
		}
		else if (commend[0] == 'B') {
			if (cursorItor != editor.begin())
				cursorItor = editor.erase(--cursorItor);
		}
		else if (commend[0] == 'P') {
			editor.insert(cursorItor, commend[2]);
		}
	}

	print(editor);
	return 0;
}