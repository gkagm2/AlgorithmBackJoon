#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define INT_MAX 2147483647

template<typename T>
void Safe_Delete_Vec(vector<T>& _vec) {
	for (size_t i = 0; i < _vec.size(); ++i) {
		if (nullptr != _vec[i]) {
			delete _vec[i];
			_vec[i] = nullptr;
		}
	}
	_vec.clear();
}


class Paint {
private:
	static int g_iId;
private:
	int m_iId;
	vector<vector<char>> m_vecMap;
	int m_iY;
	int m_iX;

public:
	Paint() : m_iY(0), m_iX(0) { m_iId = ++g_iId; }
	void SetMapSize(int _x, int _y);
	int GetId() { return m_iId; }
	int GetX() { return m_iX; }
	int GetY() { return m_iY; }
	char GetPaintType(int _x, int _y) { return m_vecMap[_y][_x]; }
	void SetPaintType(int _x, int _y, char _cType) { m_vecMap[_y][_x] = _cType; }

};
int Paint::g_iId = 0;

void Paint::SetMapSize(int _x, int _y)
{
	m_vecMap.resize(_y);
	for (int i = 0; i < m_vecMap.size(); ++i)
		m_vecMap[i].resize(_x);
	m_iX = _x;
	m_iY = _y;
}


class PaintComparator {
public:
	int GetDifferentPieceCnt(Paint* _pPaint1, Paint* _pPaint2) {
		int iDifferentCnt = 0;

		if (_pPaint1->GetX() != _pPaint2->GetX() &&
			_pPaint2->GetY() != _pPaint2->GetY())
			return iDifferentCnt;

		for (int y = 0; y < _pPaint1->GetY(); ++y) {
			for (int x = 0; x < _pPaint1->GetX(); ++x) {
				if (_pPaint1->GetPaintType(x, y) != _pPaint2->GetPaintType(x, y)) {
					++iDifferentCnt;
				}
			}
		}
		return iDifferentCnt;
	}
};


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	vector<Paint*> vecPaints;

	const int ySize = 5;
	const int xSize = 7;

	// Init & Input
	while (cnt--) {
		Paint* paint = new Paint;
		
		paint->SetMapSize(xSize, ySize);
		
		for (int y = 0; y < ySize; ++y) {
			for (int x = 0; x < xSize; ++x) {
				char cPaintType;
				cin >> cPaintType;
				paint->SetPaintType(x, y, cPaintType);
			}
		}
		vecPaints.push_back(paint);
	}


	// Compare
	int minDifferCnt = INT_MAX;
	int paint1Id = 0;
	int paint2Id = 0;

	PaintComparator comparator;

	for (int i = 0; i < vecPaints.size(); ++i) {
		for (int j = i + 1; j < vecPaints.size(); ++j) {
			int iDifferentCnt = comparator.GetDifferentPieceCnt(vecPaints[i], vecPaints[j]);
			if (minDifferCnt > iDifferentCnt) {
				minDifferCnt = iDifferentCnt;
				paint1Id = vecPaints[i]->GetId();
				paint2Id = vecPaints[j]->GetId();
			}
		}
	}

	cout << paint1Id << " " << paint2Id;

	Safe_Delete_Vec(vecPaints);

	return 0;
}
