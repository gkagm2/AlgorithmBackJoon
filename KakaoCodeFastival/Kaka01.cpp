#include<iostream>
#include<string>
using namespace std;

inline bool CommaCheck() {

}

// 대문자를 소문자로 치환
string func1(string new_id) {
	string answer = "";

	int size = new_id.size();
	int commaCnt = 0;

	for (int i = 0; i < size; ++i) {

		char c = new_id[i];
		if (c >= 65 && c <= 90) { // 대문자
			if (commaCnt > 0) {
				answer += '.';
				commaCnt = 0;
			}
			answer += (c + 32);
		}
		else if (c < 97 || c > 122) {
			if (c == '.' || c == '-' || c == '_' || (c >= 48 && c <= 57)) {
				if (c == '.') {
					++commaCnt;
				}
				else {
					if (commaCnt > 0) {
						answer += '.';
						commaCnt = 0;
					}
					answer += c;
				}

			}
		}
		else { // 보통
			if (commaCnt > 0) {
				answer += '.';
				commaCnt = 0;
			}
			answer += c;
		}
	}
	if (commaCnt > 0) {
		answer += '.';
		commaCnt = 0;
	}

	size = answer.size();
	int firstIdx = 0;
	int lastIdx = size - 1;

	if (size > 1) {
		// step 4
		// 앞글자 뒷글자 컴마 제거
		for (int i = firstIdx; i < size; ++i) {
			if (answer[i] != '.') {
				firstIdx = i;
				break;
			}
		}
		for (int i = lastIdx; i >= 0; --i) {
			if (answer[i] != '.') {
				lastIdx = i;
				break;
			}
		}

		size = answer.size();
		answer = answer.substr(firstIdx, lastIdx - firstIdx + 1);
	}
	else if (size == 1) {
		if (answer[0] == '.')
			answer = "";
	}
	
	size = answer.size();
	if (size == 0) // step 5
		answer = 'a';
	else if (size >= 16) { // step 6
		answer = answer.substr(0, 15);
	}

	lastIdx = answer.size() -1;
	
	for (int i = lastIdx; i >= 0; --i) {
		if (answer[i] != '.') {
			lastIdx = i;
			break;
		}
	}
	answer = answer.substr(0, lastIdx + 1);

	// step 7
	size = answer.size();
	if (size <= 2) {
		for (int i = 0; i < 3 - size; ++i) {
			answer += answer[size - 1];
		}
	}

	return answer;
}


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	string a = "=.=";
	cout << func1(a);


	return 0;
}