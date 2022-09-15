#include <iostream>
#include <vector>
using namespace std;

class Line {
	vector<bool> m_vecLine;
	int m_iAccLength;

public:
	void SetLength(int _iLength);
	void DrawLine(int _iStartPos, int _iEndPos);

	int GetTotalLineLength();
};

void Line::SetLength(int _iLength)
{
	m_iAccLength = 0;
	m_vecLine.empty();
	m_vecLine.resize(_iLength);
}

void Line::DrawLine(int _iStartPos, int _iEndPos)
{
	if (m_vecLine.size() <= _iEndPos || _iStartPos < 0)
		return;

	for (int i = _iStartPos; i < _iEndPos; ++i) {
		if (m_vecLine[i] == false) {
			m_vecLine[i] = true;
			++m_iAccLength;
		}
	}
}

int Line::GetTotalLineLength()
{
	return m_iAccLength;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	Line line;
	line.SetLength(10001);

	while (t--) {
		int iStartPos, iEndPos; // start , end
		cin >> iStartPos >> iEndPos;
		line.DrawLine(iStartPos, iEndPos);
	}

	int length = line.GetTotalLineLength();
	cout << length;

	return 0;
}