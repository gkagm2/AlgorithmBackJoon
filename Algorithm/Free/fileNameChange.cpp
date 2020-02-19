#include <iostream>
using namespace std;

// 파일의 길이를 구한다.
int GetLength(char *path) {
	int size = 0;
	while (path[size] != '\0') {
		++size;
	}
	return size;
}

// 파일 이름 바꾸기
void ChangeFileName(char *newFileName, char *path) {
	int startIdx;
	int endIdx;
	int i;

	int filePathLength = GetLength(path); // 기존 파일 경로의 문자 길이
	int newFileNameLength = GetLength(newFileName); // 바꿀 파일 이름의 문자 길이
	int lengthCnt = 0;
	char extensionArr[99]; // 확장명 문자열을 담을 배열

	// 파일 경로 맨 뒤에서부터 
	//.의 위치를 찾아서 endIdx에 넣어준다.
	endIdx = filePathLength - 1;
	while (path[endIdx] != '.') {
		--endIdx;
	}

	// 파일 이름이 처음 시작하는 위치를 찾아서 startIdx에 넣어준다.
	startIdx = endIdx - 1;
	while (path[startIdx] != '\\') {
		--startIdx;
	}
	startIdx++;

	// 확장 이름 가져오기
	int extensionIndex = endIdx;
	i = 0;
	while (extensionIndex < filePathLength) {
		extensionArr[i++] = path[extensionIndex++];
	}
	extensionArr[i] = '\0';
	
	// 새 파일의 이름을 삽입.
	int curPos = startIdx;
	int cnt = newFileNameLength;
	i = 0;
	while (cnt--) {
		path[curPos] = newFileName[i];
		curPos++;
		i++;
	}

	// 이름 삽입 후 뒤에다가 확장자를 붙인다.
	i = 0;
	lengthCnt = GetLength(extensionArr);
	while (lengthCnt--) {
		path[curPos] = extensionArr[i];
		i++;
		curPos++;
	}
	path[curPos] = '\0';
}

int main(int argc, int *argv[]) {
	char path[99999] = { "\\usr\\test\\project num1\\test.bild\\default.bak"}; // \가 2번으로 받아올 것임
	char newFileName[1000];

	// 바꿀 파일 이름 입력
	cout << "바꿀 파일 이름을 입력하시오 : ";
	cin.getline(newFileName, 1000);
	
	ChangeFileName(newFileName,path);

	cout << "결과 : " << path << '\n';
	return 0;
}