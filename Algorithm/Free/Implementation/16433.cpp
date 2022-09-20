#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define DIRECTION_CHECK_CNT 4

struct Vec2 {
	int x;
	int y;
	Vec2 operator +(const Vec2& _v) {return Vec2{ x + _v.x, y + _v.y }; }
	Vec2& operator++() { ++x; ++y; return *this; }
	Vec2 operator%=(int _n) { return Vec2{ x = x % _n,  y = y % _n }; }
};


enum class E_Type {
	Empty,
	Carrot,
};
char RenderToChar[] = {
	'.',
	'v'
};

Vec2 g_vDirection[DIRECTION_CHECK_CNT] = { {0,1},{1,0},{0,-1},{-1,0} };


class Map {
private:
	vector<vector<E_Type>> m_vecMap;
	int m_iXSize;
	int m_iYSize;

public:
	void SetMapSize(int _size);
	void InsertCarrot(int _x, int _y);
	
	void Optimaze(); // BFS (메모리 초과나오네)
	void Optimaze_Simple1();
	void Optimaze_Simple();
	bool IsExistCarrot();
	void Render();
	
private:
	Vec2 _FindCarrot();
	bool _IsOutOfRange(const Vec2& _vPos);
	void _InsertCarrotIdx(int _x, int _y);
};

void Map::SetMapSize(int _size)
{
	m_vecMap.resize(_size);
	for (int i = 0; i < m_vecMap.size(); ++i)
		m_vecMap[i].resize(_size);
	m_iXSize = _size;
	m_iYSize = _size;
}

void Map::InsertCarrot(int _x, int _y)
{
	m_vecMap[_y - 1][_x - 1] = E_Type::Carrot;
}

void Map::Optimaze()
{
	if (!IsExistCarrot())
		return;

	Vec2 vCarrotPos = _FindCarrot();

	// 방문체크용 2중배열 생성
	enum class E_Visited { None, Visited };
	vector<vector<E_Visited>> visited;
	
	visited.resize(m_iYSize);
	for (int y = 0; y < visited.size(); ++y)
		visited[y].resize(m_iXSize);


	queue<Vec2> q;
	q.push(vCarrotPos);

	while (!q.empty()) {
		Vec2 vCurPos = q.front();
		q.pop();
		
		visited[vCurPos.y][vCurPos.x] = E_Visited::Visited;
		
		// empty일 경우  4방향을 체크한다음
		if (E_Type::Empty == m_vecMap[vCurPos.y][vCurPos.x]) {
			bool isExistCarrot = false;
			for (int i = 0; i < DIRECTION_CHECK_CNT; ++i) {
				Vec2 vCheckPos = vCurPos + g_vDirection[i];
				if (_IsOutOfRange(vCheckPos))
					continue;
				if (E_Type::Carrot == m_vecMap[vCheckPos.y][vCheckPos.x]) {
					isExistCarrot = true;
					break;
				}
			}

			if(!isExistCarrot)
				m_vecMap[vCurPos.y][vCurPos.x] = E_Type::Carrot;
		}

		for (int i = 0; i < DIRECTION_CHECK_CNT; ++i) {
			Vec2 vCheckPos = vCurPos + g_vDirection[i];
			if (_IsOutOfRange(vCheckPos))
				continue;

			if (E_Visited::Visited == visited[vCheckPos.y][vCheckPos.x])
				continue;
			q.push(vCheckPos);
		}
	}
}

void Map::Optimaze_Simple1()
{
	if (!IsExistCarrot())
		return;

	Vec2 vCarrotPos = _FindCarrot();
	Vec2 vStartPos = { vCarrotPos.x % 2, vCarrotPos.y % 2 };

	for (int y = 0; y < m_iYSize; ++y) {
		for (int x = 0; x < m_iXSize; ++x) {
			if (x % 2 == vStartPos.x && y % 2 == vStartPos.y) {
				_InsertCarrotIdx(x, y);
			}
		}
	}
	++vStartPos;
	vStartPos %= 2;

	for (int y = 0; y < m_iYSize; ++y) {
		for (int x = 0; x < m_iXSize; ++x) {
			if (x % 2 == vStartPos.x && y % 2 == vStartPos.y) {
				_InsertCarrotIdx(x, y);
			}
		}
	}
}

void Map::Optimaze_Simple()
{
	if (!IsExistCarrot())
		return;

	Vec2 vCarrotPos = _FindCarrot();

	for (int y = 0; y < m_iYSize; ++y) {
		for (int x = 0; x < m_iXSize; ++x) {
			if ((vCarrotPos.x + vCarrotPos.y) % 2 == (x + y) % 2)
				_InsertCarrotIdx(x, y);
		}
	}
}

bool Map::IsExistCarrot()
{
	for (int y = 0; y < m_vecMap.size(); ++y) {
		for (int x = 0; x < m_vecMap[y].size(); ++x) {
			if (E_Type::Carrot == m_vecMap[y][x]) {
				return true;
			}
		}
	}
	return false;
}

void Map::Render()
{
	for (int y = 0; y < m_vecMap.size(); ++y) {
		for (int x = 0; x < m_vecMap[y].size(); ++x) {
			E_Type mapState = m_vecMap[y][x];
			cout << RenderToChar[(int)mapState];
		}
		cout << "\n";
	}
}

Vec2 Map::_FindCarrot()
{
	Vec2 vPos;
	for (int y = 0; y < m_vecMap.size(); ++y) {
		for (int x = 0; x < m_vecMap[y].size(); ++x) {
			if (E_Type::Carrot == m_vecMap[y][x]) {
				vPos.x = x;
				vPos.y = y;
			}
		}
	}
	return vPos;
}

bool Map::_IsOutOfRange(const Vec2& _vPos)
{
	return _vPos.x < 0 || _vPos.y < 0 || _vPos.x >= m_iXSize || _vPos.y >= m_iYSize;
}

void Map::_InsertCarrotIdx(int _x, int _y)
{
	m_vecMap[_y][_x] = E_Type::Carrot;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int size, y, x;
	cin >> size >> y >> x;

	Map map;
	map.SetMapSize(size);
	map.InsertCarrot(x, y);
	map.Optimaze_Simple();
	//map.Optimaze_Simple1();
	//map.Optimaze();
	map.Render();

	return 0;
}