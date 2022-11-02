#include <iostream>
#include <vector>
using namespace std;

enum class E_Type {
	triangle = 1,
	square,
	circle,
	star,
	end = star
};
enum class E_ResultType {
	pA_win,
	pB_win,
	draw,
};
struct Ttakji {
public:
	E_Type eType;
};

class Player {
private:
	vector<Ttakji> m_vecTakji;

public:
	int GetTakjiCount(E_Type _eType) const {
		int iCnt = 0;
		for (int i = 0; i < m_vecTakji.size(); ++i) {
			if (_eType == m_vecTakji[i].eType)
				++iCnt;
		}
		return iCnt;
	}

	void Init() {
		m_vecTakji.resize(0);
	}

	vector<Ttakji>& GetTakjies() {
		return m_vecTakji;
	}
};

E_ResultType Play(const Player& _playerA, const Player& _playerB) {
	E_ResultType eResultType = E_ResultType::draw;

	int iTypeCnt = (int)E_Type::end;
	for (int i = 0; i < iTypeCnt; ++i) {
		int iACnt = _playerA.GetTakjiCount(E_Type(iTypeCnt - i));
		int iBCnt = _playerB.GetTakjiCount(E_Type(iTypeCnt - i));
		if (iACnt == iBCnt)
			continue;

		eResultType = iACnt > iBCnt ? E_ResultType::pA_win : E_ResultType::pB_win;
		break;
	}
	return eResultType;
}

void AddTakji(Player& _player) {
	int iTakjiTypeCnt;
	cin >> iTakjiTypeCnt;

	vector<Ttakji>& vecTakji = _player.GetTakjies();
	vecTakji.resize(iTakjiTypeCnt);

	for (int i = 0; i < iTakjiTypeCnt; ++i) {
		int iTakjiType;
		cin >> iTakjiType;
		vecTakji[i] = (Ttakji{ (E_Type)iTakjiType });
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Player p1, p2;

	int iRoundCnt;
	cin >> iRoundCnt;

	while (iRoundCnt--) {
		p1.Init();
		p2.Init();

		AddTakji(p1);
		AddTakji(p2);

		E_ResultType eResult = Play(p1, p2);

		if (eResult == E_ResultType::pA_win)
			cout << "A\n";
		else if (eResult == E_ResultType::pB_win)
			cout << "B\n";
		else
			cout << "D\n";
	}

	return 0;
}