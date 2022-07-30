#include <iostream>
#include <string>
using namespace std;
#define MAX_ROOM_SIZE 100
#define WALL 'X'
#define SPACE '.'

int GetLieDownWidthCount(const char room[][MAX_ROOM_SIZE], int roomSize) {
	int lieDownCnt = 0;

	int accCnt = 0;
	for (int y = 0; y < roomSize; ++y) {
		if (accCnt >= 2)
			++lieDownCnt;
		accCnt = 0;
		for (int x = 0; x < roomSize; ++x) {
			if (WALL == room[y][x]) {
				if (accCnt >= 2) {
					++lieDownCnt;
				}
				accCnt = 0;
			}
			else if (SPACE == room[y][x])
				++accCnt;
		}
	}
	if (accCnt >= 2)
		++lieDownCnt;

	return lieDownCnt;
}

int GetLieDownHeightCount(const char room[][MAX_ROOM_SIZE], int roomSize) {
	int lieDownCnt = 0;

	int accCnt = 0;
	for (int x = 0; x < roomSize; ++x) {
		if (accCnt >= 2)
			++lieDownCnt;
		accCnt = 0;
		for (int y = 0; y < roomSize; ++y) {
			if (WALL == room[y][x]) {
				if (accCnt >= 2) {
					++lieDownCnt;
				}
				accCnt = 0;
			}
			else if (SPACE == room[y][x])
				++accCnt;
		}
	}
	if (accCnt >= 2)
		++lieDownCnt;

	return lieDownCnt;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	char room[MAX_ROOM_SIZE][MAX_ROOM_SIZE];

	int roomSize;
	cin >> roomSize;
	for (int y = 0; y < roomSize; ++y) {
		for (int x = 0; x < roomSize; ++x) {
			char input;
			cin >> input;
			room[y][x] = input;
		}
	}

	int iWidthCnt = GetLieDownWidthCount(room, roomSize);
	int iHeightCnt = GetLieDownHeightCount(room, roomSize);
	cout << iWidthCnt << " " << iHeightCnt;

	return 0;
}