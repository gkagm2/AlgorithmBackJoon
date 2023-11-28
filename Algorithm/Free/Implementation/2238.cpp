#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Human {
private:
	string m_strName;
	int m_iOrder;
	int m_iPrice;
	bool m_bInvalidity;

public:
	Human() : m_strName(""), m_iOrder(0), m_iPrice(0), m_bInvalidity(false) {}
public:
	const string& GetName() { return m_strName; }
	int GetOrder() { return m_iOrder; }
	int GetPrice() { return m_iPrice; }
	bool IsInvalidity() { return m_bInvalidity; }

	void SetName(const string& _strName) { m_strName = _strName; }
	void SetOrder(int _iOrder) { m_iOrder = _iOrder; }
	void SetPrice(int _iPrice) { m_iPrice = _iPrice; }
	void SetInvalidity(bool _bInvalidity) { m_bInvalidity = _bInvalidity; }
};

class AuctionManager {
private:
	vector<Human> m_vList;
public:
	void Insert(const string& _strName, int _iPrice);
	int GetSamePriceHumanCount(int _iPrice);
	Human* GetWinningBidder(const int _iUpperLimitPrice);
	bool AreAllInvalid();
};

void AuctionManager::Insert(const string& _strName, int _iPrice) {

	Human newHuman;

	newHuman.SetName(_strName);
	newHuman.SetPrice(_iPrice);
	int iSameCnt = GetSamePriceHumanCount(newHuman.GetPrice());

	if (iSameCnt > 0) {
		for (int i = 0; i < m_vList.size(); ++i) {
			if (_iPrice == m_vList[i].GetPrice())
				m_vList[i].SetInvalidity(true);
		}
		newHuman.SetInvalidity(true);
	}

	newHuman.SetOrder(iSameCnt + 1);
	m_vList.push_back(newHuman);
}

int AuctionManager::GetSamePriceHumanCount(int _iPrice)
{
	int iCount = 0;
	for (int i = 0; i < m_vList.size(); ++i) {
		int iPrice = m_vList[i].GetPrice();
		if (_iPrice == iPrice)
			++iCount;
	}
	return iCount;
}
Human* AuctionManager::GetWinningBidder(const int _iUpperLimitPrice)
{
	Human* pHuman = nullptr;
	bool bInvalid = AreAllInvalid();
	if (bInvalid) {
		
		int minPrice = _iUpperLimitPrice;
		for (int i = 0; i < m_vList.size(); ++i) {
			int iCurPrice = m_vList[i].GetPrice();
			if (iCurPrice < minPrice)
				minPrice = iCurPrice;
		}

		vector<Human*> vList;
		for (int i = 0; i < m_vList.size(); ++i) {
			if (minPrice == m_vList[i].GetPrice())
				vList.push_back(&m_vList[i]);
		}

		for (int i = 0; i < vList.size(); ++i) {
			if (1 == vList[i]->GetOrder()) {
				vList[i]->GetPrice();
				pHuman = vList[i];
			}
		}
	}
	else {
		vector<Human*> vList;
		for (int i = 0; i < m_vList.size(); ++i) {
			if (false == m_vList[i].IsInvalidity())
				vList.push_back(&m_vList[i]);
		}
		int iLowerPrice = _iUpperLimitPrice;
		for (int i = 0; i < vList.size(); ++i) {
			
			if (iLowerPrice >= vList[i]->GetPrice()) {
				iLowerPrice = vList[i]->GetPrice();
				pHuman = vList[i];
			}
		}
	}
	return pHuman;
}

bool AuctionManager::AreAllInvalid()
{
	int iCount = 0;
	for (int i = 0; i < m_vList.size(); ++i) {
		if (m_vList[i].IsInvalidity())
			++iCount;
	}
	if (iCount == m_vList.size())
		return true;

	return false;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int u, n; // u : 상한, n : 경매에 참여한 횟수
	cin >> u >> n;

	AuctionManager manager;

	while (n--) {
		string strName;
		int iPrice;
		cin >> strName >> iPrice;
		manager.Insert(strName, iPrice);
	}

	
	Human* winningBidder = manager.GetWinningBidder(u);

	cout << winningBidder->GetName() << " " << winningBidder->GetPrice() << "\n";

	return 0;
}
