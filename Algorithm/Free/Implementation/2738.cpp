#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
	vector<vector<int>> mat;
	int x, y;
public:
	void Resize(int _x, int _y) {
		x = _x;
		y = _y;
		mat.resize(_y);
		for (int i = 0; i < _y; ++i)
			mat[i].resize(_x);
	}
	void SetEle(int _x, int _y, int _value) {
		mat[_y][_x] = _value;
	}
	int GetEle(int _x, int _y) const {
		return mat[_y][_x];
	}
	int GetXSize() const { return x; }
	int GetYSize() const { return y; }

	void Render() {
		for (int i = 0; i < y; ++i) {
			for (int j = 0; j < x; ++j) {
				cout << GetEle(j, i) << " ";
			}
			cout << "\n";
		}
	}
};

Matrix AddMatrix(const Matrix& mat1, const Matrix& mat2) {
	int xSize = mat1.GetXSize();
	int ySize = mat1.GetYSize();

	Matrix mat;
	mat.Resize(xSize, ySize);
	for (int y = 0; y < ySize; ++y) {
		for (int x = 0; x < xSize; ++x) {
			mat.SetEle(x, y, mat1.GetEle(x, y) + mat2.GetEle(x, y));
		}
	}
	return mat;
}

void InputMatrix(Matrix* _mat, int _x, int _y) {
	_mat->Resize(_x, _y);
	for (int y = 0; y < _y; ++y) {
		for (int x = 0; x < _x; ++x) {
			int inputEle;
			cin >> inputEle;
			_mat->SetEle(x, y, inputEle);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	Matrix matA;
	Matrix matB;

	InputMatrix(&matA, m, n);
	InputMatrix(&matB, m, n);

	Matrix mat = AddMatrix(matA, matB);

	mat.Render();

	return 0;
}