#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Card {
private:
	int hp;
	int atk;
public:
	void SetAtk(int _atk) { atk = _atk; }
	int GetAtk() { return atk; }
	void SetHp(int _hp) { hp = _hp; }
	int GetHp() { return hp; }
};

class Player {
private:
	string m_strName;
	bool m_isDead;
	Card m_tCard;
public:
	Card& GetCard() { return m_tCard; }
	void SetDead(bool _isDead) { m_isDead = _isDead; }
	bool IsDead() { return m_isDead; }
	bool IsDead() const { return m_isDead; }
	void SetName(const string& _strName) { m_strName = _strName; }
	string GetName() { return m_strName; }

public:
	Player() : m_strName(""), m_isDead(false), m_tCard() {}
};


void Crash(Player& _p1, Player& _p2) {
	_p1.GetCard().SetHp(max(0, _p1.GetCard().GetHp() - _p2.GetCard().GetAtk()));
	_p2.GetCard().SetHp(max(0, _p2.GetCard().GetHp() - _p1.GetCard().GetAtk()));
	if (0 == _p1.GetCard().GetHp())
		_p1.SetDead(true);

	if (0 == _p2.GetCard().GetHp())
		_p2.SetDead(true);
}

string GetResult(Player& _p1, Player& _p2) {
	string strResult = "";
	if (_p1.IsDead() && _p2.IsDead()) {
		strResult = "DRAW";
	}
	else if (_p1.IsDead())
		strResult = "PLAYER " + _p2.GetName();
	else if (_p2.IsDead())
		strResult = "PLAYER " + _p1.GetName();
	else
		strResult = "NobodyDead";

	return strResult;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Player p1, p2;
	p1.SetName("A");
	p2.SetName("B");

	// -- input--
	int hp, atk;
	cin >> atk >> hp;
	p1.GetCard().SetAtk(atk);
	p1.GetCard().SetHp(hp);

	cin >> atk >> hp;
	p2.GetCard().SetAtk(atk);
	p2.GetCard().SetHp(hp);

	while (1) {
		Crash(p1, p2);
		string strResult = GetResult(p1, p2);
		if (strResult == "NobodyDead")
			continue;

		cout << strResult;
		break;
	}

	return 0;
}