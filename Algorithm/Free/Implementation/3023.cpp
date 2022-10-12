#include <iostream>
#include <vector>
using namespace std;

class Card {
private:
	const static char g_arrPaintRenderWord[2];
	vector<vector<char>> m_vecMap;
	int m_iX;
	int m_iY;
public:
	void SetMapSize(int _x, int _y) {
		m_iX = _x;
		m_iY = _y;

		m_vecMap.resize(_y);
		for (int i = 0; i < m_vecMap.size(); ++i)
			m_vecMap[i].resize(_x);
	}

	void Paint(int _x, int _y, char _c) {
		m_vecMap[_y][_x] = _c;
	}

	void Expansion(int _iMaxX, int _iMaxY) {
		int iNewX = _iMaxX * 2;
		int iNewY = _iMaxY * 2;
		SetMapSize(iNewX, iNewY);

		for (int y = 0; y < _iMaxY; ++y) {
			for (int x = 0; x < _iMaxX; ++x) {
				int x2, y2;
				x2 = m_iX - x - 1;
				y2 = y;
				m_vecMap[y2][x2] = m_vecMap[y][x];
			}
		}

		for (int y = 0; y < _iMaxY; ++y) {
			for (int x = 0; x < iNewX; ++x) {
				int x2, y2;
				y2 = m_iY - y - 1;
				x2 = x;
				m_vecMap[y2][x2] = m_vecMap[y][x];
			}
		}
	}

	void Render() {
		for (int i = 0; i < m_iY; ++i) {
			for (int j = 0; j < m_iX; ++j) {
				cout << m_vecMap[i][j];
			}
			cout << "\n";
		}
	}

	void Flap(int _x, int _y) {
		char flapC = m_vecMap[_y - 1][_x - 1] == g_arrPaintRenderWord[0] ? g_arrPaintRenderWord[1] : g_arrPaintRenderWord[0];
		m_vecMap[_y - 1][_x - 1] = flapC;
	}
};

const char Card::g_arrPaintRenderWord[] = { '#','.' };

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int x, y;

	cin >> y >> x;

	Card card;
	card.SetMapSize(x, y);
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			char c;
			cin >> c;
			card.Paint(j, i, c);
		}
	}
	card.Expansion(x, y);

	int iFlapX, iFlapY;
	cin >> iFlapY >> iFlapX;
	card.Flap(iFlapX, iFlapY);

	card.Render();

	return 0;
}