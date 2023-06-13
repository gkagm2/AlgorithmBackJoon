#include <iostream>
#include <cstring>
using namespace std;

#define MAX_DP_CNT 41

class Fibonacci {
private:
	int m_iFibCodeCallCnt;
	int m_iFibDpCodeCallCnt;

	int m_arrF[MAX_DP_CNT];
public:
	int Fib(int n);
	int FibDP(int n);
public:
	Fibonacci() : m_iFibCodeCallCnt(0), m_iFibDpCodeCallCnt(0) {
		memset(m_arrF, 0, sizeof(int) * MAX_DP_CNT);
	}
public:
	int GetFibCallCnt() { return m_iFibCodeCallCnt; }
	int GetFibDpCallCnt() { return m_iFibDpCodeCallCnt; }
};

int Fibonacci::Fib(int n) {
	if (1 == n || 2 == n) {
		++m_iFibCodeCallCnt;
		return 1; 
	}
	else
		return (Fib(n - 1) + Fib(n - 2));
}

int Fibonacci::FibDP(int n) {
	m_arrF[1] = m_arrF[2] = 1;
	for (int i = 3; i <= n; ++i) {
		++m_iFibDpCodeCallCnt;
		m_arrF[i] = m_arrF[i - 1] + m_arrF[i - 2];
	}
	return m_arrF[n];
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Fibonacci fib;

	int n;
	cin >> n;

	fib.Fib(n);
	fib.FibDP(n);

	cout << fib.GetFibCallCnt() << " " << fib.GetFibDpCallCnt();
	return 0;
}
