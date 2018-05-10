#include <iostream>
using namespace std;
struct st {
	double el;
	st *next;
};
bool simv(char c) { //проверка символ ли это
	if (c >= 'a'&&c <= 'z') return true;
	return false;
}
void putStack(double x, st *&top) { //поместить число в стек
	st *elem = new st;
	elem->el = x;
	elem->next = top;
	top = elem;
}
double toDouble(char c) { //получить значение переменной
	switch (c) {
	case 'a': return 8.6;
	case 'b': return 2.4;
	case 'c': return 5.1;
	case 'd': return 0.3;
	case 'e': return 7.9;
	default: return 0;
	}
}
double oper(char c, double x, double y) {//вычисляет результат операции
	double res = 0;
	switch (c) {
	case '+': res = x + y; break;
	case '-': res = y - x; break;
	case '*': res = x*y; break;
	case '/': res = y / x; break;
	}
	return res;
}
double getStack(st *&top) { //извлечь из стека
	if (top == NULL) return -3000;
	st *tmp = top;
	double x = top->el;
	top = top->next;
	delete tmp;
	return x;
}
void clearStack(st *&top) { //очистка стека
	while (top != NULL) {
		st *tmp = top;
		top = top->next;
		delete tmp;
	}
}
double calculate(char *str) {
	st *top = NULL;//указатель на вершину стека
	char *tmp = str;
	while (*tmp != '\0') {
		if (simv(*tmp)) {
			putStack(toDouble(*tmp),top);
		}
		else {
			double x = getStack(top);
			double y = getStack(top);
			double r = oper(*tmp,x,y);
			putStack(r,top);
		}
		tmp++;
	}
	double result = getStack(top);
	clearStack(top);
	return result;	
}
void main(){
	setlocale(LC_ALL, "rus");
	char Out[128] = "abc-/de+*";
	printf("\nПольская запись = %s\n", Out);       // Выводим на экран результат
	double result=calculate(Out);
	cout << "Результат расчета= " << result << endl;
	system("pause");
}
