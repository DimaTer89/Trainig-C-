/*Создайте приложение для работы с массивом структур, содержащим сведения о простоях конвейера:
* дата (массив из трех чисел);
* простои в 1 смену (в часах);
* простои во 2-ю смену (в часах).
Приложение должно выполнять следующие функции:
* Инициализация массива из 5 тестовых элементов (чтение данных из файла);
* Удаление последнего элемента в массиве;
* Вывод на экран всей информации о простоях, упорядоченного по дате;
* Вывод на экран общей суммы простоев, которые произошли в течение месяца, введенного пользователем. Если данные о простоях отсутствуют, то должно быть выведено соответствующее сообщение.
* Завершение работы программы с записью текущего состояния массива в файл.*/
#include <iostream>
#define N 3
using namespace std;
struct konveer {
	int date[N];
	int	downtimeIntheFirstShiftl;
	int	downtimeInthSecondShift;
};
void printOne(konveer *a,int m) {
	cout << " Дата : ";
	for (int j = 0; j < m; j++) {
		cout << a->date[j] << " ";
	}
	cout << endl;
	cout << " Простои в первую смену (в часах): " << a->downtimeIntheFirstShiftl << endl;
	cout << " Простои во вторую смену (в часах): " << a->downtimeInthSecondShift << endl;
}
void getFile(FILE* in, konveer *a, int n,int m) {
	char buffer[256];
	for (int i = 0; i < n; i++, a++) {
		fgets(buffer, sizeof(buffer), in);
		char *word, *next;
		word = strtok_s(buffer, " /", &next);
		for (int j = 0; j < m; j++) {
			a->date[j] = atoi(word);
			word = strtok_s(NULL, " /", &next);
		}
		a->downtimeIntheFirstShiftl = atoi(word);
		word = strtok_s(NULL, " /", &next);
		a->downtimeInthSecondShift = atoi(word);
	}
}
void print(konveer *a, int n,int m) {
	for (int i = 0; i < n; i++, a++) {
		cout << " Запись № " << i + 1 << endl;
		cout << " Дата : ";
		for (int j = 0; j < m; j++) {
			cout << a->date[j] << " ";
		}
		cout << endl;
		cout << " Простои в первую смену (в часах): " << a->downtimeIntheFirstShiftl << endl;
		cout << " Простои во вторую смену (в часах): " << a->downtimeInthSecondShift << endl;
	}
}
void delLast(konveer *&a, int &n, int m) {
	konveer *ptr = new konveer[n - 1];
	for (int i = 0; i < n - 1; i++) {
		ptr[i] = a[i];
	}
	delete[]a;
	a = ptr;
	n--;
}
void sort(konveer a[], int n, int m) {
	int radix = 10;
	konveer **ptr = new konveer*[n];
	for (int i = 0; i < n; i++) {
		ptr[i] = &a[i];
	}
	for (int k = n - 1; k > 0; k--) {
		char buf[128];
		char bufer[128];
		char *ptr;
		for (int l = 0; l < m; l++) {
			ptr = itoa(a[k].date[l], buf, radix);
			strcat_s(bufer, ptr);
		}
		for (int i = 0; i < k; i++) {
			char bufr[128];
			char buffer[128];
			char *p;
			for (int j = 0; j < m; j++) {
				p = itoa(a[i].date[j], bufr, radix);
				strcat_s(buffer, p);
			}
			if()
		}
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	FILE* in;
	int kol = 5;
	char filename[128];
	cout << " Введите имя файла для чтения : ";
	cin >> filename;
	if (fopen_s(&in, filename, "r") != NULL) {
		cout << " Не удалось открыть файл для записи \n";
		system("pause");
		return;
	}
	konveer *kon = new konveer[kol];
	getFile(in, kon, kol,N);
	print(kon, kol,N);
	int menu;
	do {
		cout << " 1 -  Удаление последнего элемента в массиве \n";
		cout << " 2 - Вывод на экран всей информации о простоях, упорядоченного по дате \n";
		cout << " 3 - Вывод на экран общей суммы простоев, которые произошли в течение месяца, введенного пользователем.Если данные о простоях отсутствуют, то должно быть выведено соответствующее сообщение. \n";
		cout << " 0 - выход \n";
		do {
			cin >> menu;
			if (menu < 0 || menu>3)cout << " Ошибка ! Введите снова !\n";
		} while (menu < 0 || menu>3);
		switch (menu) {
		case 1:
			delLast(kon, kol, N);
			print(kon, kol, N);
			break;
		case 2:
			sort(kon, kol, N);
			break;
		}
	} while (menu != 0);
	system("pause");
}
