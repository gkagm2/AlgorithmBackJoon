#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN     (-2147483647 - 1)
#define INT_MAX       2147483647

struct Vector2 {
public:
	int x;
	int y;
	Vector2() : x(0), y(0) {}
	Vector2(int _x,int _y) : x(_x), y(_y) {}
};
enum class E_State {
	empty = 0,
	attached,
};

struct Paper {
public: 
	vector<vector<E_State>> m_vecArea;
	int m_w;
	int m_h;

	Vector2 m_vLBPos; // LB : Left Bottom Pos : Position
	
public:
	virtual void SetSize(int _x, int _y) { 
		int xSize = _x + 1;
		int ySize = _y + 1;
		m_vecArea.resize(ySize);
		for (int i = 0; i < m_vecArea.size(); ++i)
			m_vecArea[i].resize(xSize);
	}
	virtual void SetWidthHeight(int _w, int _h) {
		m_w = _w;
		m_h = _h;
	}
	void SetLBPos(Vector2 _vLBPos){ m_vLBPos = _vLBPos; }
	Vector2 GetLBPos() { return m_vLBPos; }
	Vector2 GetRTPos() { return Vector2(m_vLBPos.x + m_w - 1, m_vLBPos.y + m_h - 1); }
	int GetLBX() { return m_vLBPos.x; }
	int GetLBY() { return m_vLBPos.y; }
	int GetWidth() { return m_w; }
	int GetHeight() { return m_h; }
};

struct BackgroundPaper : public Paper {
private:
	//attacted paper area
	Vector2 m_vAttactedMinPos;
	Vector2 m_vAttactedMaxPos;
public:
	virtual void SetSize(int _x, int _y) override {
		Paper::SetSize(_x, _y);
		m_vAttactedMaxPos.x = 0;
		m_vAttactedMaxPos.y = 0;
	}
	
	virtual void SetWidthHeight(int _w, int _h) override {
		Paper::SetWidthHeight(_w, _h);
		m_vAttactedMinPos.x = m_w;
		m_vAttactedMinPos.y = m_h;
	}

	void AttachedPaper(Paper _tOtherPaper) {
		Vector2 vLBPos = _tOtherPaper.GetLBPos();
		Vector2 vRTPos = _tOtherPaper.GetRTPos();
		for (int y = vLBPos.y; y <= vRTPos.y; ++y) {
			for (int x = vLBPos.x; x <= vRTPos.x; ++x) {
				if (!IsOutOfPos(x, y))
					m_vecArea[y][x] = E_State::attached;
			}
		}
		if (m_vAttactedMinPos.x > _tOtherPaper.GetLBX())
			m_vAttactedMinPos.x = _tOtherPaper.GetLBX();
		if (m_vAttactedMinPos.y > _tOtherPaper.GetLBY())
			m_vAttactedMinPos.y = _tOtherPaper.GetLBY();
		if (m_vAttactedMaxPos.x < _tOtherPaper.GetRTPos().x)
			m_vAttactedMaxPos.x = _tOtherPaper.GetRTPos().x;
		if (m_vAttactedMaxPos.y < _tOtherPaper.GetRTPos().y)
			m_vAttactedMaxPos.y = _tOtherPaper.GetRTPos().y;
	}
	void ClearBackground() {
		for (int i = 0; i < m_vecArea.size(); ++i) {
			for (int j = 0; j < m_vecArea[i].size(); ++j)
				m_vecArea[i][j] = E_State::empty;
		}
	 }
	bool IsOutOfPos(int _x, int _y) {
		if (m_w <= _x ||
			m_h <= _y ||
			0 > _x ||
			0 > _y) {
			return true;
		}
		return false;
	}

	bool IsExistAttactedPaper() {
		for (int i = 0; i < m_h; ++i) {
			for (int j = 0; j < m_w; ++j) {
				if (E_State::attached == m_vecArea[i][j])
					return true;
			}
		}
		return false;
	}

	int GetAttachedAreaSize() {
		Vector2 vArea;
		vArea.x = m_vAttactedMaxPos.x + 1 - m_vAttactedMinPos.x;
		vArea.y = m_vAttactedMaxPos.y + 1 - m_vAttactedMinPos.y;
		return vArea.x * vArea.y;
	}

	int GetEmptyAreaSizeInAttachedArea() {
		int area = 0;
		for (int y = 0; y < m_h; ++y) {
			for (int x = 0; x < m_w; ++x) {
				if (E_State::attached == m_vecArea[y][x])
					++area;
			}
		}
		return area;
	}
	void Render() {
		for (int y = 0; y < GetRTPos().y + 1; ++y) {
			for (int x = 0; x < GetRTPos().x + 1; ++x) {
				if (!IsOutOfPos(x, y)) {
					if (E_State::empty == m_vecArea[GetRTPos().y - y][x])
						cout << "бр";
					else
						cout << "бс";
				}
			}
			cout << "\n";
		}
	}
};
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	BackgroundPaper paper;
	paper.SetSize(100, 100);
	paper.SetWidthHeight(100, 100);

	int cnt;
	cin >> cnt;

	int x, y;

	for (int i = 0; i < cnt; ++i) {
		cin >> x >> y;
		Paper blackPaper;
		blackPaper.SetSize(10, 10);
		blackPaper.SetWidthHeight(10, 10);
		blackPaper.SetLBPos(Vector2(x, y));
		paper.AttachedPaper(blackPaper);

		//paper.Render();
		//cout << "\n";
	}

	int size = paper.GetEmptyAreaSizeInAttachedArea();
	cout << size;
	return 0;
}