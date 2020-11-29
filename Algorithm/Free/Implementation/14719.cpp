#include <iostream>
#include <cstring>
using namespace std;


class Map {
private:
	int **map; // left top is zero pos
	int w, h;

	enum State {
		eSpace,
		eColumn,
		eWater
	};

public:
	Map(const int &_h, const int &_w) : h(_h), w(_w) {
		map = new int*[h];
		for (int i = 0; i < h; ++i) {
			map[i] = new int[w];
			memset(map[i], eSpace, sizeof(int) * w);
		}
	};
	~Map() {
		for (int i = 0; i < h; ++i) {
			delete[] map[i];
		}
		delete[] map;
	}
	
	void SetColumn(const int& xPos, const int &height) {
		for (int i = 0; i < height; ++i) {
			map[i][xPos] = eColumn;
		}
	}

	int GetWaterSpaceCnt() {
		int totalWaterSpaceCnt = 0;
		for (int y = 0; y < h; ++y) {
			int colCnt = 0;
			int tempWaterSpaceCnt = 0;
			for (int x = 0; x < w; ++x) {
				if (colCnt > 0 && map[y][x] == eSpace) {
					++tempWaterSpaceCnt;
				}
				else if (map[y][x] == eColumn) {
					totalWaterSpaceCnt += tempWaterSpaceCnt;
					// Code for drawing
					/*for (int c = x - tempWaterSpaceCnt; c < x; ++c) {
						map[y][c] = eWater;
					}*/
					++colCnt;
					tempWaterSpaceCnt = 0;
				}
			}

			if (colCnt <= 1)
				break;
		}
		return totalWaterSpaceCnt;
	}
	/*
	void Draw() {
		for (int i = h - 1; i >= 0; --i) {
			for (int j = 0; j < w; ++j) {
				if (map[i][j] == eColumn)
					cout << "бс";
				else if (map[i][j] == eSpace)
					cout << "  ";
				else if (map[i][j] == eWater)
					cout << "бр";
			}
			cout << "\n";
		}
	}
	*/
};

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int h, w;

	cin >> h >> w;
	Map map(h, w);

	for (int pos = 0; pos < w; ++pos) {
		int colHeight;
		cin >> colHeight;
		map.SetColumn(pos, colHeight);
	}
	cout << map.GetWaterSpaceCnt() << "\n";
	// map.Draw();

	return 0;
}