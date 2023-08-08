#include <iostream>
#include <vector>
using namespace std;

class Part {
private:
	int m_iGroupNum;
	int m_iProcessNum;
	int m_iWeight;
	int m_iSize;

public:
	int GetGroupNum() { return m_iGroupNum; }
	void SetGroupNum(int _iGroupNum) { m_iGroupNum = _iGroupNum; }
	int GetProcessNum() { return m_iProcessNum; }
	void SetProcessNum(int _iProcessNum) { m_iProcessNum = _iProcessNum; }
	int GetWeight() { return m_iWeight; }
	void SetWeight(int _iWeight) { m_iWeight = _iWeight; }
	int GetSize() { return m_iSize; }
	void SetSize(int _iSize) { m_iSize = _iSize; }

public:
	Part() : m_iGroupNum(0), m_iProcessNum(0), m_iWeight(0), m_iSize(0) {}
};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;

	cin >> t;

	int iGroupNum = 1;
	vector<Part> vParts;
	while (t--) {
		int iPartCount;
		cin >> iPartCount;

		Part tMaxPart;
		int iMaxSize, iMaxWeight;

		cin >> iMaxSize >> iMaxWeight;

		tMaxPart.SetSize(iMaxSize);
		tMaxPart.SetWeight(iMaxWeight);

		for (int i = 0; i < iPartCount; ++i) {
			Part tPart;
			int iSize, iWeight;
			cin >> iSize >> iWeight;
			tPart.SetGroupNum(iGroupNum);
			tPart.SetProcessNum(i + 1);
			tPart.SetSize(iSize);
			tPart.SetWeight(iWeight);
			vParts.push_back(tPart);
		}

		cout << "Material Management " << iGroupNum << "\n";
		cout << "Classification ---- End!\n";

		++iGroupNum;
	}

	return 0;
}