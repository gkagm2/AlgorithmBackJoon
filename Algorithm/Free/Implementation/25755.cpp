// https://www.acmicpc.net/problem/25755
#include <iostream>
#include <vector>
using namespace std;

int flip[9] = { 1,5,0,0,2,0,0,8,0 };

void Swap(int& _a, int& _b) {
	int t = _a;
	_a = _b;
	_b = t;
}


void Flip(vector<vector<int>>& _mat, char _cDir) {
	int iSize = _mat.size();

	for (int y = 0; y < iSize; ++y) {
		for (int x = 0; x < iSize; ++x) {
			int idx = _mat[y][x] - 1;
			_mat[y][x] = flip[idx];
		}
	}

	switch(_cDir) {
	case 'L': case 'R': {
		for (int y = 0; y < iSize; ++y) {
			for (int x = 0; x < int(iSize * 0.5); ++x) {
				Swap(_mat[y][x], _mat[y][iSize - x - 1]);
			}
		}

	}
		break;
	case 'U': case 'D': {
		for (int y = 0; y < int(iSize * 0.5); ++y) {
			for (int x = 0; x < iSize; ++x) {
				Swap(_mat[y][x], _mat[iSize - y - 1][x]);
			}
		}
	}
	default:
		break;
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	char cDir;
	int iSize;

	cin >> cDir >> iSize;

	vector<vector<int>> mat;
	mat.resize(iSize);
	for (int i = 0; i < mat.size(); ++i)
		mat[i].resize(iSize);

	for (int y = 0; y < iSize; ++y) {
		for (int x = 0; x < iSize; ++x) {
			int input;
			cin >> input;
			mat[y][x] = input;
		}
	}


	Flip(mat, cDir);
	
	for (int y = 0; y < mat.size(); ++y) {
		for (int x = 0; x < mat[y].size(); ++x) {
			if (0 == mat[y][x])
				cout << "? ";
			else
				cout << mat[y][x] << " ";
		}
		cout << "\n";
	}

	return 0;
}
