#include <iostream>
#define N 10
#include <time.h>
using namespace std;
void randMas(int *ptr, int n) {
	for (int i = 0; i < n; i++, ptr++) {
		*ptr = rand() % 21 - 10;
	}
}
void printMas(int *ptr, int n) {
	for (int i = 0; i < n; i++, ptr++) {
		cout << " " << *ptr;
	}
	cout << endl;
}
int fisNeg(int *ptr, int n) {
	int k = 0;
	for (int i = 0; i < n; i++, ptr++) {
		if (*ptr < 0) {
			k = i;
			break;
		}
	}
	return k;
}
int lasNeg(int *ptr, int n) {
	int k = 0;
	ptr +=n-1;
	for (int i = n-1; i > 0; i--, ptr--) {
		if (*ptr <0) {
			k = i;
			break;
		}
	}
	return k;
}
int score(int *ptr, int *endPtr) {
	int kol = 0;
	while (ptr+1 < endPtr) {
		kol++;
		ptr++;
	}
	return kol;
}
void rekurs(int *ptr, int *ptr2) {
	int tmp = *ptr;
	*ptr = *ptr2;
	*ptr2 = tmp;
}
void sortMas(int mas[], int n) {
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (mas[i] > mas[i + 1]) {
				int tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
			}
		}
	}
}

void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int mas[N];
	int *ptr = mas;
	randMas(ptr, N);
	cout << " Исходный массив \n";
	printMas(ptr, N);
	int neg1 = fisNeg(ptr, N);
	int neg2 = lasNeg(ptr, N);
	int *tmp = ptr + neg1;
	int *temp = ptr + neg2;
	int kol = score(tmp, temp);
	cout << " Количество элементов между найденными элементами = " << kol << endl;
	cout << " Изменный массив \n";
	rekurs(tmp, temp);
	ptr=mas;
	printMas(ptr, N);
	cout << " Отсортированный массив \n";
	sortMas(mas, N);
	ptr=mas;
	printMas(ptr, N);
	system("pause");
}
