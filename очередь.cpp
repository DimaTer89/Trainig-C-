#include<iostream>
#include <Windows.h>
using namespace std;
struct client
{
	char name[50];
	int prior;
	char time[10];
	client* next,*prev;
};
struct timePrint
{
	char timeName[10];
	timePrint* next, *prev;
};
struct statistic
{
	char name[50];
	int prior;
	timePrint* head,*tail;
	statistic* next, *prev;
};
class printer
{
	statistic* headStat, *tailStat;
	timePrint* headTime,*tailTime;
	client* head,*tail;
public:
	printer()
	{
		head = tail = NULL;
		headTime = tailTime = NULL;
		headStat = tailStat = NULL;
	}
	printer(const printer& ob)
	{

	}
	void push(char* str, int prior,char* time);
	void addQueque(char* str);
	void show();
	void showStat();
	void pushStat(char* str, int prior,char* time);

};
void printer::pushStat(char* str, int prior,char* time)
{
	statistic* tmp = new statistic;
	statistic* temp = headStat;
	bool flag = false;
	while (temp)
	{
		if (strcmp(temp->name, str) == 0)
		{
			flag = true;
			addQueque(time);
			break;
		}
		temp = temp->next;
	}
	if (flag == false)
	{
		strcpy(tmp->name, str);
		tmp->prior = prior;
		addQueque(str);
		tmp->next = NULL;
		if (headStat != NULL)
		{
			tmp->prev = tailStat;
			tailStat->next = tmp;
			tailStat = tmp;
		}
		else
		{
			tmp->prev = NULL;
			headStat = tmp;
			tailStat = tmp;
		}
	}
}

void printer::addQueque(char* str)
{
	{
		timePrint* tmp = new timePrint;
		strcpy(tmp->timeName, str);
		tmp->next = NULL;
		if (head != NULL)
		{
			tmp->prev = tailTime;
			tailTime->next = tmp;
			tailTime = tmp;
		}
		else
		{
			tmp->prev = NULL;
			headTime = tailTime = tmp;
		}
	}
}
void printer::push(char* str,int prior,char* time)
{
	client* new_cell = new client;
	strcpy(new_cell->name, str);
	new_cell->prior = prior;
	strcpy(new_cell->time, time);

	if (head == NULL)
	{
		new_cell->next = NULL;
		new_cell->prev = NULL;
		head = tail = new_cell;
		
	}
	if (head!=NULL&&head->prior > new_cell->prior)
	{
		new_cell->next = head;
		head->prev = new_cell;
		new_cell->prev = NULL;
		new_cell = head;
		
	}
	if (head!=NULL&& tail->prior <= new_cell->prior)
	{
		new_cell->next = NULL;
		new_cell->prev = tail;
		tail->next = new_cell;
		tail = new_cell;
		
		
	}
	if (tail->prior > new_cell->prior)
	{
		client* after_me = tail;
		while (after_me!=head&&after_me->prior > new_cell->prior)
		{
			after_me = after_me->prev;
		}
		new_cell->next = after_me->next;
		after_me->next = new_cell;
	    after_me->next->prev = new_cell;
		new_cell->prev = after_me;
		
	}
}

void printer::show()
{
	client* tmp = head;
	while (tmp)
	{
		cout << " Должность : " << tmp->name << endl;
		cout << " Время : " << tmp->time << endl;
		tmp = tmp->next;
		cout << endl;
	}
}
void printer::showStat()
{
	statistic* tmp = headStat;
	timePrint* temp = headTime;
	while (tmp)
	{
		cout << " Должность : " << tmp->name << endl;
		cout << " Время печати : ";
		while (temp)
		{
			cout << temp->timeName << ", ";
			temp = temp->next;
		}
		tmp = tmp->next;
		cout << endl;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char name[50];
	char time[10];
	int prior;
	int menu;
	printer ob;
	do
	{
		system("cls");
		cout << " 1 - Добавить клиента \n";
		cout << " 2 - Показать всех клиентов \n";
		cout << " 3 - Статистика печати \n";
		cout << " 0 - Выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		cin.ignore();
		switch (menu)
		{
		case 1:
			cout << " Введите должность клиента ( директор, менеджер, охранник) : ";
			gets_s(name, 50);
			if (strcmp(name, "директор") == 0)
				prior = 1;
			if (strcmp(name, "менеджер") == 0)
				prior = 2;
			if (strcmp(name, "охранник") == 0)
				prior = 3;
			cout << " Введите время (формат - чч:мм) : ";
			gets_s(time, 10);
			ob.push(name, prior,time);
			break;
		case 2:
			system("cls");
			cout << " Все клиенты  \n";
			ob.show();
			system("pause");
			break;
		case 3:
			system("cls");
			cout << " Статистика печати \n";
			ob.showStat();
			system("pause");
			break;
		case 0:
			cout << " До свидания ! \n";
			break;
		}

	} while (menu != 0);
	system("pause");
	return 1;
}
