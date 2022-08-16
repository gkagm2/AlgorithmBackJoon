#include <iostream>
#include <vector>
using namespace std;

class Bingo {
public:
	struct Ele {
		int num;
		bool check;
		Ele() : num(0), check(false){}
	};
private:
	int m_x;
	int m_y;
	vector<vector<Ele>> m_panel;

	int m_maxBingoCnt;
	
public:
	Bingo() : m_x(5), m_y(5), m_maxBingoCnt(3) { SetSize(m_x, m_y); }
	void InitPanelNum();
	void SetSize(int _x, int _y);
	bool IsBingo();
	void CheckNum(int _num);
	int GetBingoCount();
	void Render();
};

int Bingo::GetBingoCount()
{
	int curBingoCnt = 0;
	int checkCnt;
	int maxHitCnt = m_x;
	// 가로 체크
	for (int i = 0; i < m_y; ++i) {
		checkCnt = 0;
		for (int j = 0; j < m_x; ++j) {
			if (m_panel[i][j].check)
				++checkCnt;
		}
		if (checkCnt == maxHitCnt)
			++curBingoCnt;
	}

	// 세로 체크
	for (int i = 0; i < m_x; ++i) {
		checkCnt = 0;
		for (int j = 0; j < m_y; ++j) {
			if (m_panel[j][i].check)
				++checkCnt;
		}
		if (checkCnt == maxHitCnt)
			++curBingoCnt;
	}

	// 대각선 체크
	checkCnt = 0;
	for (int i = 0; i < m_x; ++i) {
		if (m_panel[i][i].check)
			++checkCnt;
	}
	if (checkCnt == maxHitCnt)
		++curBingoCnt;

	checkCnt = 0;
	for (int i = 0; i < m_x; ++i) {
		if (m_panel[i][m_x - 1 - i].check)
			++checkCnt;
	}
	if (checkCnt == maxHitCnt)
		++curBingoCnt;

	return curBingoCnt;
}

void Bingo::InitPanelNum() {
	for (int i = 0; i < m_y; ++i) {
		for (int j = 0; j < m_x; ++j) {
			Ele input;
			cin >> input.num;
			m_panel[i][j] = input;
		}
	}
}

void Bingo::SetSize(int _x, int _y) {
	m_panel.resize(_y);
	for (int i = 0; i < _y; ++ i)
		m_panel[i].resize(_x);
}

bool Bingo::IsBingo() {
	int curBingoCnt = GetBingoCount();
	return curBingoCnt >= m_maxBingoCnt ? true : false;
}

void Bingo::CheckNum(int _num) {
	for (int i = 0; i < m_y; ++i) {
		for (int j = 0; j < m_x; ++j) {
			if (m_panel[i][j].num == _num) {
				m_panel[i][j].check = true;
			}
		}
	}
}

void Bingo::Render() {
	static int RenderCnt = 0;
	cout << " Render Count : " << ++RenderCnt << " Current Bingo Count : " << GetBingoCount() << " "<< "\n";
	for (int i = 0; i < m_y; ++i) {
		for (int j = 0; j < m_x; ++j) {
			if (m_panel[i][j].check)
				cout << "X\t";
			else
				cout << m_panel[i][j].num << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Bingo cheolsuBingo;

	int answer = 0;
	bool isGetAnswer = false;

	cheolsuBingo.InitPanelNum();

	for (int hostTalkCnt = 1; hostTalkCnt <= 25; ++hostTalkCnt) {
		int inputNum;
		cin >> inputNum;
		
		cheolsuBingo.CheckNum(inputNum);
		if (!isGetAnswer && cheolsuBingo.IsBingo()) {
			answer = hostTalkCnt;
			isGetAnswer = true;
		}
		//cheolsuBingo.Render();
	}

	cout << answer;

	return 0;
}