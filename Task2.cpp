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
===============================================================
	#include <iostream>
using namespace std;
#include <Windows.h>
struct data {
	int day;
	int month;
	int year;
};
struct prostoi {
	struct data dat;
	int smena1;
	int smena2;
};
void razbor(char *str, prostoi *elem) {
	char *word, *next;
	word=strtok_s(str, " ", &next);
	elem->dat.day=atoi(word);
	word = strtok_s(NULL, " ", &next);
	elem->dat.month = atoi(word);
	word = strtok_s(NULL, " ", &next);
	elem->dat.year = atoi(word);
	word = strtok_s(NULL, " ", &next);
	elem->smena1 = atoi(word);
	word = strtok_s(NULL, " ", &next);
	elem->smena2 = atoi(word);
};
void print(prostoi *list, int n) {
	cout << " Список простоев \n";
	for (int i = 0; i < n; i++) {
		cout << list[i].dat.day << "/" << list[i].dat.month << "/" << list[i].dat.year;
		cout << " 1 смена: " << list[i].smena1 << ", 2 смена: "  << list[i].smena2 << endl;
	}
	cout << endl;
}
void readData(FILE *in, prostoi *&list, int &n) {
	fscanf_s(in, "%d\n", &n);
	list = new prostoi[n];
	char str[128];
	int i;
	for (i = 0; i < n; i++) {
		if (fgets(str, 128, in) == NULL)break;
			razbor(str,list+i);
	}
	if (i != n) {
		cout << " Ошибка чтения !\n";
		system("pause");
		exit(0);
	}
};
void udal(prostoi *&list, int &n) {
	prostoi *ptr = new prostoi[n - 1];
	for (int i = 0; i < n - 1; i++) {
		ptr[i] = list[i];
	}
	delete[]list;
	list = ptr;
	n--;
};
int datacmp(struct data one,struct data two) {
	if (one.year > two.year)return 1;
	if (one.year < two.year)return -1;
	if (one.month > two.month)return 1;
	if (one.month < two.month)return -1;
	if (one.day > two.day)return 1;
	if (one.day < two.day)return -1;
	return 0;
};
void printSort(prostoi *list, int n) {
	prostoi **tmp = new prostoi*[n];
	for (int i = 0; i < n; i++) {
		tmp[i] = list + i;
	}
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (datacmp(tmp[i]->dat, tmp[i + 1]->dat) > 0) {
				prostoi *ptr = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = ptr;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << tmp[i]->dat.day << "/" << tmp[i]->dat.month << "/" << tmp[i]->dat.year;
		cout << " 1 смена: " << tmp[i]->smena1 << ", 2 смена: " << tmp[i]->smena2 << endl;
	}
}
int sumProst(prostoi *list, int n, int month,int year) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (list[i].dat.month == month && list[i].dat.year==year) {
			sum += list[i].smena1;
			sum += list[i].smena2;
		}
	}
	return sum;
}
void writeData(FILE *out, prostoi *list, int n) {
	fprintf(out, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(out, "%d %d %d %d %d\n", list[i].dat.day, list[i].dat.month, list[i].dat.year, list[i].smena1, list[i].smena2);
	}
}
void clearList(prostoi *&list, int &n) {
	delete[]list;
	list = NULL;
	n = 0;
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int N = 128;
	int n;
	prostoi *list;
	FILE *in, *out;
	char filename[N];
	cout << " Введите имя файла для чтения : ";
	cin >> filename;
	if (fopen_s(&in, filename, "r") != NULL) {
		cout << " Не удалось открыть файл для чтения \n";
		system("pause");
		return;
	}
	readData(in, list, n);
	printSort(list, n);
	int m;
	cout << " Введите номер месяца : ";
	cin >> m;
	int y;
	cout << " Введите номер года : ";
	cin >> y;
	int sum = sumProst(list, n, m,y);
	if (sum == 0) {
		cout << " Данных о простоев нет \n";
	}
	else {
		cout << " Сумма простоев = " << sum << endl;
	}
	udal(list, n);
	cout << " Список после удаления \n";
	print(list, n);
	fclose(in);
	cout << " Введите имя файла для вывода : ";
	cin >> filename;
	if (fopen_s(&out, filename, "w") != NULL) {
		cout << " Не удалось открыть файл для записи \n";
		system("pause");
		return;
	}
	writeData(out, list, n);
	fclose(out);
	clearList(list, n);
	cout << " Работа успешно завершена.... \n";
	system("pause");
}
