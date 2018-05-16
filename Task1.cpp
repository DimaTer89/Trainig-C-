/*Сформируйте массив из 5 элементов, организовав ввод с консоли (все элементы массива различные).
Найдите максимальный и минимальный элементы и поменяйте их местами. Если минимальный элемент положительный, то определите произведение элементов массива.
В противном случае найдите сумму элементов.Выполните сортировку массива методом пузырька.*/
#include <iostream>
#define N 5
using namespace std;
void vvod(int *ptr,int n) {
	for (int i = 0; i < n; i++, ptr++) {
		cin >> *ptr;
	}
}
void print(int *ptr, int n) {
	for (int i = 0; i < n; i++, ptr++) {
		cout << " "<< *ptr;
	}
	cout << endl;
}
int max(int *ptr, int n) {
	int max = *ptr;
	int k = 0;
	for (int i = 0; i < n; i++, ptr++) {
		if (*ptr > max) {
			max = *ptr;
			k = i;
		}
	}
	return k;
}
int min(int *ptr, int n,int *ind) {
	int min = *ptr;
	int k = 0;
	for (int i = 0; i < n; i++, ptr++) {
		if (*ptr < min) {
			min = *ptr;
			*ind = *ptr;
			k = i;
		}
	}
	return k;
}
int proiz(int *ptr, int min, int n) {
	int proiz = 1;
	for (int i = 0; i < n; i++, ptr++) {
			proiz *= *ptr;
	}
	return proiz;
}
int sum(int *ptr, int min, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++, ptr++) {
		sum+= *ptr;
	}
	return sum;
}
void main() {
	setlocale(LC_ALL, "rus");
	int mas[N];
	int *ptr;
	ptr = mas;
	int mInd;
	int *Iptr = &mInd;
	cout << " Введите элементы массива через пробел : ";
	vvod(ptr, N);
	ptr = mas;
	cout << " Исходный массив \n";
	print(ptr, N);
	int maxInd = max(ptr, N);
	int minInd = min(ptr, N,Iptr);
	cout << " Максимальный элемент индекс = " << maxInd << endl;
	cout << " Минимальный элемент индекс = " << minInd << endl;
	ptr = mas;
	int tmp = *(ptr + maxInd);
	*(ptr + maxInd) = *(ptr + minInd);
	*(ptr + minInd) = tmp;
	ptr = mas;
	print(ptr, N);
	ptr = mas;
	if (mInd > 0)cout << " Произведение элементов массива = " << proiz(ptr, minInd, N) << endl;
	if(mInd<0) cout << " Сумма элементов массива = " << sum(ptr, minInd, N)<<endl;
	system("pause");
}
==============================================
	int fisNeg(int mas[], int n) {
	int tmp = 0;
	for (int i=0;i<n;i++) {
		if (mas[i] < 0) {
			tmp = mas[i];
			break;
		}
		;
	}
	return tmp;
}
