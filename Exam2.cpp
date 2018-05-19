#include <iostream>
#include <Windows.h>
#define N 128
using namespace std;
struct vokzal {
	char name[N];
	char desname[N];
	int numname;
};
void razbor(vokzal *dest, char *str) {
	char *word, *next;
	word = strtok_s(str, " /", &next);
	strcpy_s(dest->name, word);
	word = strtok_s(NULL, " /", &next);
	strcpy_s(dest->desname, word);
	word = strtok_s(NULL, " /", &next);
	dest->numname = atoi(word);
}
void readData(FILE *in, vokzal *&dest, int &n) {
	fscanf_s(in, "%d\n", &n);
	dest = new vokzal[n];
	char str[N];
	int i;
	for (i = 0; i < n; i++) {
		if (fgets(str, N, in) == NULL)break;
		razbor(dest+i, str);
	}
	if (i != n) {
		cout << " Ошибка чтения !\n";
		system("pause");
		exit(0);
	}
}
void print(vokzal *dest, int n) {
	for (int i = 0; i < n; i++) {
		cout << " Маршрут № " << i + 1 << endl;
		cout << dest[i].name << " - " << dest[i].desname << " - " << dest[i].numname << endl;
	}
}
//izmen(dest, n, num);
void sortNum(vokzal *dest, int n) {
	vokzal **ptr = new vokzal*[n];
	for (int i = 0; i < n; i++) {
		ptr[i] = dest + i;
	}
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (ptr[i]->numname > ptr[i + 1]->numname) {
				vokzal *tmp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << " Маршрут № " << i + 1 << endl;
		cout << ptr[i]->name << " - " << ptr[i]->desname << " - " << ptr[i]->numname << endl;
	}
}
void change(vokzal *dest, int n,char *str) {
	for (int i = 0; i < n; i++) {
		if (strcmp(dest[i].name, str) == 0 || strcmp(dest[i].desname, str) == 0) {
			cout << " Маршрут № " << i + 1 << endl;
			cout << dest[i].name << " - " << dest[i].desname << " - " << dest[i].numname << endl;
		}
	}
}
void writeData(FILE *out, vokzal *dest, int n) {
	fprintf(out, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(out, " %s / %s / %d \n", dest[i].name, dest[i].desname, dest[i].numname);
	}
}
void clear(vokzal *&dest,int &n) {
	delete[]dest;
	dest = NULL;
	n = 0;
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE *in, *out;
	int n;
	char filename[N];
	cout << " Введите имя файла для чтения : ";
	cin >> filename;
	if (fopen_s(&in, filename, "r") != NULL) {
		cout << " Не удалось открыть файл для чтения \n";
		system("pause");
		return;
	}
	cout << " Введите имя файла для записи : ";
	cin >> filename;
	if (fopen_s(&out, filename, "w") != NULL) {
		cout << " Не удалось открыть файл для записи \n";
		system("pause");
		return;
	}
	vokzal *dest;
	readData(in, dest, n);
	fclose(in);
	print(dest, n);
	/*int num;
	cout << " Введите номер элемента для изменения : ";
	cin >> num;
	izmen(dest, n,num);*/
	cout << " Отсортированный массив \n";
	sortNum(dest, n);
	char name[N];
	cout << " Введите название маршрута : ";
	cin >> name;
	change(dest, n,name);
	writeData(out, dest, n);
	clear(dest, n);
	fclose(out);
	system("pause");
}
