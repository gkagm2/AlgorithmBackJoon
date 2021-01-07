// 감시카메라 CCTV 아직 덜품.

#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

int map[8][8];
int orgMap[8][8];


struct Dir {
	int x;
	int y;
	Dir() : x(0), y(0) {}
	Dir(int _x, int _y) : x(_x), y(_y) {}
	Dir& operator+=(const Dir&d);
};
Dir& Dir::operator+=(const Dir &d) {
	x += d.x;
	y += d.y;
	return *this;
}

int x;
int y;
vector<Dir> curCamsPos;

vector<Dir> cctv1 = { Dir(1, 0) };
vector<Dir> cctv2 = { Dir(1, 0), Dir(-1, 0) };
vector<Dir> cctv3 = { Dir(1, 0), Dir(0, -1) };
vector<Dir> cctv4 = { Dir(1, 0), Dir(-1, 0), Dir(0, -1) };
vector<Dir> cctv5 = { Dir(1, 0), Dir(-1, 0), Dir(0, -1), Dir(0, 1) };
vector<Dir> camDirList[] = { cctv1, cctv2, cctv3, cctv4, cctv5 };

// 90 Rotate CW
void GetRotateCCTVDir(vector<Dir> &vec,const vector<Dir>& _cctv) {
	for (int i = 0; i < _cctv.size(); ++i) {
		Dir dir;
		if (_cctv[i].x == 1 && _cctv[i].y == 0) { // left -> down
			dir.x = 0;
			dir.y = 1;
		}
		else if (_cctv[i].x == 0 && _cctv[i].y == 1) { // down -> left
			dir.x = -1;
			dir.y = 0;
		}
		else if (_cctv[i].x == -1 && _cctv[i].y == 0) { // left -> up
			dir.x = 0;
			dir.y = -1;
		}
		else if (_cctv[i].x == 0 && _cctv[i].y == -1) { // up -> right
			dir.x = 1;
			dir.y = 0;
		}
		vec.push_back(dir);
	}
}

void InitMap(int x, int y) {
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			map[i][j] = orgMap[i][j];
		}
	}
}

void Draw(const int &x, const int &y) {
	cout << "\n";
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			if (map[i][j] == 9)
				cout << "#" << " ";
			else
				cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}


void SetCCTVArea() {
	// 감시카메라에서 찍힌 영역을 한번 렌더링 함.
	for (int i = 0; i < curCamsPos.size(); ++i) {
		Dir pos = curCamsPos[i];
		int camIdx = map[pos.y][pos.x] - 1; // camera number

		//search

		// 방향으로 쭉 가서 체크하기
		for (int d = 0; d < camDirList[camIdx].size(); ++d) {
			Dir curPos = pos;
			while (true) {
				curPos += camDirList[camIdx][d];
				// 끝에 다다랐으면
				if (curPos.x < 0 || curPos.y < 0 || curPos.x >= x || curPos.y >= y)
					break;
				if (map[curPos.y][curPos.x] == 6) // 벽에 만났으면
					break;
				if (map[curPos.y][curPos.x] == 0) // 땅이면
					map[curPos.y][curPos.x] = 9;
				if (map[curPos.y][curPos.x] > 0 && map[curPos.y][curPos.x] < 6)  // 카메라를 만났으면
					continue;
			}
			Draw(x, y);
			Sleep(1000);
			system("cls");
		}
	}
	Draw(x, y);
}



int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> y >> x;

	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			cin >> map[i][j];
			orgMap[i][j] = map[i][j];

			// camera found 
			if (map[i][j] > 0 && map[i][j] < 6) {
				curCamsPos.push_back(Dir(j, i));
			}
		}
	}
	Draw(x, y);
	
	vector<Dir> orgDir = curCamsPos;
	for (int i = 0; i < curCamsPos.size(); ++i) {

		// 회전 시키기
		vector<Dir> rotDir = camDirList[i];
		for (int j = 0; j < 4; +j) { // 방향 조절
			vector<Dir> newDir;
			GetRotateCCTVDir(newDir, rotDir);
			rotDir = newDir;
		}
		SetCCTVArea();
		InitMap(x, y);
	}
	curCamsPos = orgDir;

	return 0;
}