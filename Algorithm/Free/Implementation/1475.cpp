#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct NumCard {
public:
	static int g_cnt;
public:
	bool isUsed[10];
	NumCard() {
		for (int i = 0; i <= 9; ++i)
			isUsed[i] = false;
		++g_cnt;
	}

public:
	bool UseNum(char _cNum) {
		int iNum = _cNum - '0';
		bool isChanged = false;
		if (6 == iNum || 9 == iNum) {
			if (!isUsed[6]) {
				isUsed[6] = true;
				isChanged = true;
			}
			else if (!isUsed[9]) {
				isUsed[9] = true;
				isChanged = true;
			}
		}
		else {
			if (!isUsed[iNum]) {
				isUsed[iNum] = true;
				isChanged = true;
			}
		}
		return isChanged;
	}

	bool IsUsed(char _cNum) {
		int iNum = _cNum - '0';
		return isUsed[iNum];
	}
};

int NumCard::g_cnt = 0;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<NumCard> vecNum;

	string doorNum;
	int g_cnt = 0;
	cin >> doorNum;

	// 모든 번호 검사
	for (int i = 0; i < doorNum.size(); ++i) {
		char num = doorNum[i];

		bool isSuccess = false;
		// 순회
		for (int j = 0; j < vecNum.size(); ++j) {
			// 순회 도중에 숫자를 넣는다.
			isSuccess = vecNum[j].UseNum(num);
			if (isSuccess)
				break;
		}
		// 실패하면 
		if (!isSuccess) {
			NumCard newNumCard;
			vecNum.push_back(newNumCard);
			int idx = vecNum.size() - 1;
			vecNum[idx].UseNum(num);
		}
	}

	cout << NumCard::g_cnt;

	return 0;
}