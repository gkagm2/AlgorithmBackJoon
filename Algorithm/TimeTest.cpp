#include <iostream>
#include <ctime>

using namespace std;

int main() {

	clock_t start, finish;
	double duration;
	start = clock();

	// Time Test code

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC; //CLOCK_PER_SEC : 10000
	printf("at %f second\n", duration);

	return 0;
}