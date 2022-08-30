#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 코드 중복이 많다. 리펙토링은 귀찮으므로 스킵


char IToC(int num) {
	return (char)(num + 48);
}
enum class E_Type {
	vertical,
	horizon,
	none
};

class Bingo {
private:
	int m_x;
	int m_y;
	vector<vector<int>> m_panel;

public:
public:
	Bingo(int _x, int _y) : m_x(_x), m_y(_y) {
		m_panel.resize(m_y);
		for (int i = 0; i < m_panel.size(); ++i)
			m_panel[i].resize(m_x);
	}
public:
	int GetX() { return m_x; }
	int GetY() { return m_y; }
	void SetBingoNumber(int _x, int _y, int _num) {
		m_panel[_y][_x] = _num;
	}
	int GetNumber(int _x, int _y) { return m_panel[_y][_x]; }
};


class Player {
private:
	string m_strName;
public:
	void SetName(const string& _strName) {
		m_strName = _strName;
	}
	void CrashBingo(Bingo* _pBingo, int _iCrashNum) {
		E_Type eType = E_Type::none;
		char cCrashNum = IToC(_iCrashNum);
		int nineCnt = 0;
		int curNineCnt = 0;
		int mX;
		int mY;

		// Horizon check
		for (int y = 0; y < _pBingo->GetY(); ++y) {
			curNineCnt = 0;
			for (int x = 0; x < _pBingo->GetX(); ++x) {
				int number = _pBingo->GetNumber(x, y);
				string strNum = to_string(number);

				for (int i = 0; i < strNum.size(); ++i) {
					if (cCrashNum == strNum[i]) {
						++curNineCnt;
					}
				}
			}
			if (nineCnt < curNineCnt) {
				eType = E_Type::horizon;
				nineCnt = curNineCnt;
				mY = y;
			}
		}

		// vertical check
		for (int x = 0; x < _pBingo->GetX(); ++x) {
			curNineCnt = 0;
			for (int y = 0; y < _pBingo->GetY(); ++y) {
				int number = _pBingo->GetNumber(x, y);
				string strNum = to_string(number);

				for (int i = 0; i < strNum.size(); ++i) {
					if (cCrashNum == strNum[i]) {
						++curNineCnt;
					}
				}
			}
			if (nineCnt < curNineCnt) {
				eType = E_Type::vertical;
				nineCnt = curNineCnt;
				mX = x;
			}
		}

		// crash bingo
		switch (eType) {
		case E_Type::horizon:
			for (int x = 0; x < _pBingo->GetX(); ++x)
				_pBingo->SetBingoNumber(x, mY, 0);
			break;
		case E_Type::vertical:
			for (int y = 0; y < _pBingo->GetY(); ++y)
				_pBingo->SetBingoNumber(mX, y, 0);
			break;
		default:
			break;
		}
	}
	int GetNumberCnt(Bingo* _pBingo, int _iTargetNum) {
		char targetNum = IToC(_iTargetNum);
		int nineCnt = 0;

		for (int y = 0; y < _pBingo->GetY(); ++y) {
			for (int x = 0; x < _pBingo->GetX(); ++x) {
				int number = _pBingo->GetNumber(x, y);
				string strNum = to_string(number);

				for (int i = 0; i < strNum.size(); ++i) {
					if (targetNum == strNum[i]) {
						++nineCnt;
					}
				}
			}
		}
		return nineCnt;
	}
};


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);


	Player *player = new Player;
	player->SetName("준오");

	int n, m;
	cin >> n >> m;

	Bingo *bingo = new Bingo(m, n);

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			int num;
			cin >> num;
			bingo->SetBingoNumber(x, y, num);
		}
	}

	player->CrashBingo(bingo, 9);
	int nineCnt = player->GetNumberCnt(bingo, 9);

	cout << nineCnt;

	delete player;
	delete bingo;

	return 0;
}