// 속도문제 (DP로 풀어야될듯)
/*
ex)
6 6
0 0 0 1 0 0
0 0 0 2 1 0
0 0 2 0 0 0
0 1 0 0 0 0
2 0 0 0 0 0
0 0 0 0 0 0

answer : 3
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
	int x;
	int y;
	Pos() : x(0), y(0){}
	Pos(int _x, int _y) : x(_x), y(_y){}
};

enum class E_Type {
	Field,
	Tree,
	Stone
};

class Ground {
public:
	int m_iX;
	int m_iY;

	vector<vector<E_Type>> m_vecGround;
	E_Type m_eType;

public:
	int GetModifiableMaxGroundSize();
	void SetGroundSize(int _x, int _y);
	E_Type GetGroundType(int _x, int _y);
	void SetGroundType(int _x, int _y, E_Type _eType);
};

int Ground::GetModifiableMaxGroundSize()
{
	int iBiggerstOffSize = 0;
	for (int iStartY = 0; iStartY < m_iY; ++iStartY) {
		for (int iStartX = 0; iStartX < m_iX; ++iStartX) {
			int iOffsetSize = 0;

			while (true) {
				bool isKeepFinding = true;

				for (int y = iStartY; y <= iStartY + iOffsetSize; ++y) {
					for (int x = iStartX; x <= iStartX + iOffsetSize; ++x) {
						
						bool bIsOutOfPos = (x < 0 || x >= m_iX || y < 0 || y >= m_iY) ? true : false;
						if (bIsOutOfPos) {
							isKeepFinding = false;
							break;
						}

						E_Type curGroundType = m_vecGround[y][x];
						if (E_Type::Stone == curGroundType ||
							E_Type::Tree == curGroundType) {
							isKeepFinding = false;
							break;
						}
					}
					if (isKeepFinding == false)
						break;
				}
				if (isKeepFinding==false)
					break;
				++iOffsetSize;
			}
			
			if (iBiggerstOffSize < iOffsetSize)
				iBiggerstOffSize = iOffsetSize;
		}
	}

	return iBiggerstOffSize;
}

void Ground::SetGroundSize(int _x, int _y)
{
	m_iX = _x;
	m_iY = _y;

	m_vecGround.resize(_y);
	for (int i = 0; i < m_iY; ++i)
		m_vecGround[i].resize(m_iX);
}

E_Type Ground::GetGroundType(int _x, int _y)
{
	return m_vecGround[_y][_x];
}

void Ground::SetGroundType(int _x, int _y, E_Type _eType)
{
	m_vecGround[_y][_x] = _eType;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);


	Ground* pGround;
	pGround = new Ground;
	
	int m, n;
	cin >> m >> n;
	
	// Input Data
	pGround->SetGroundSize(m, n);
	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < n; ++x) {
			int iType;
			cin >> iType;
			pGround->SetGroundType(x,y,(E_Type)iType);
		}
	}

	// Get Size
	int iSize = pGround->GetModifiableMaxGroundSize();

	cout << iSize;

	delete pGround;

	return 0;
}