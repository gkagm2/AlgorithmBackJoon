#include <iostream>
#include <vector>

long long sum(std::vector<int> &a) {
	long long s = 0;

	for (long long i = 0; i < a.size(); ++i) {
		s += a[i];
	}
	return s;
}

int main() {
	return 0;
}