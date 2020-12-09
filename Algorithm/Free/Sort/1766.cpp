// used Topology sort
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> questions[32001];
int inDegree[100001];
vector<int> result;
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n, m; // n : ������ �� , m : ������ ���� ������ ����
	cin >> n >> m;

	int questionNum, degreeNum;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= m; ++i) {
		cin >> questionNum >> degreeNum;
		questions[questionNum].push_back(degreeNum);
		++inDegree[degreeNum];
	}

	// inDegree�� ���� node�� ã�´�.
	for (int i = 1; i <= n; ++i) {
		// ���� ���� queue�� �־��ش�.
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int x = q.top();
		q.pop();

		result.push_back(x); // ť���� ���� ������ ���������� ����

		// ���� ��忡 ����Ǿ��ִ� ��� �������� Ȯ���Ͽ� y node�� ����Ǿ��ִ� ������ ����.
		for (int j = 0; j < questions[x].size(); ++j) {
			int y = questions[x][j];
			if (--inDegree[y] == 0) // ����Ǿ��ִ� ������ ��������
				q.push(y);
		}
	}

	for (auto v : result)
		cout << v << " ";

	return 0;
}