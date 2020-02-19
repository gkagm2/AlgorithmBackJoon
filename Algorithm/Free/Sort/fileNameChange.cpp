#include <iostream>
using namespace std;

// ������ ���̸� ���Ѵ�.
int GetLength(char *path) {
	int size = 0;
	while (path[size] != '\0') {
		++size;
	}
	return size;
}

// ���� �̸� �ٲٱ�
void ChangeFileName(char *newFileName, char *path) {
	int startIdx;
	int endIdx;
	int i;

	int filePathLength = GetLength(path); // ���� ���� ����� ���� ����
	int newFileNameLength = GetLength(newFileName); // �ٲ� ���� �̸��� ���� ����
	int lengthCnt = 0;
	char extensionArr[99]; // Ȯ��� ���ڿ��� ���� �迭

	// ���� ��� �� �ڿ������� 
	//.�� ��ġ�� ã�Ƽ� endIdx�� �־��ش�.
	endIdx = filePathLength - 1;
	while (path[endIdx] != '.') {
		--endIdx;
	}

	// ���� �̸��� ó�� �����ϴ� ��ġ�� ã�Ƽ� startIdx�� �־��ش�.
	startIdx = endIdx - 1;
	while (path[startIdx] != '\\') {
		--startIdx;
	}
	startIdx++;

	// Ȯ�� �̸� ��������
	int extensionIndex = endIdx;
	i = 0;
	while (extensionIndex < filePathLength) {
		extensionArr[i++] = path[extensionIndex++];
	}
	extensionArr[i] = '\0';
	
	// �� ������ �̸��� ����.
	int curPos = startIdx;
	int cnt = newFileNameLength;
	i = 0;
	while (cnt--) {
		path[curPos] = newFileName[i];
		curPos++;
		i++;
	}

	// �̸� ���� �� �ڿ��ٰ� Ȯ���ڸ� ���δ�.
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
	char path[99999] = { "\\usr\\test\\project num1\\test.bild\\default.bak"}; // \�� 2������ �޾ƿ� ����
	char newFileName[1000];

	// �ٲ� ���� �̸� �Է�
	cout << "�ٲ� ���� �̸��� �Է��Ͻÿ� : ";
	cin.getline(newFileName, 1000);
	
	ChangeFileName(newFileName,path);

	cout << "��� : " << path << '\n';
	return 0;
}