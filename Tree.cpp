#include <iostream>
using namespace std;
#define N 128
struct song {
	char name[N];
	char artist[N];
	double time;
};
struct node {
	song *s;
	node *left;
	node *right;
};
song *parsing(char *buffer) {
	song*elem = new song;
	char *word, *next;
	word = strtok_s(buffer, "/", &next);
	strcpy_s(elem->name, word);
	word = strtok_s(NULL, "/", &next);
	strcpy_s(elem->artist, word);
	word = strtok_s(NULL, "/", &next);
	elem->time = atof(word);
	return elem;
};
void putInTree(song *&elem, node *&root) {
	if (root == NULL) {
		//поместить в корень
		root = new node;
		root->s = elem;
		root->left = NULL;
		root->right = NULL;
	}
	else {
		if (strcmp(elem->name, root->s->name) < 0) {
			putInTree(elem, root->left);
			return;
		}
		if (strcmp(elem->name, root->s->name) > 0) {
			putInTree(elem, root->right);
			return;
		}
		root->s->time += elem->time;
		delete elem;
		elem = NULL;
	}
};
node *createTree(FILE *in, node *&root) {
	char buffer[N];
	while (fgets(buffer, N, in) != NULL) {
		song *elem = parsing(buffer);
		putInTree(elem, root);//поместить песню в дерево
	}
	return root;
};
void printTree(node* root) {
	if (root == NULL)return;
	printTree(root->left);
	cout << root->s->name << " " << root->s->artist << " " << root->s->time << endl;
	printTree(root->right);
};
void clearTree(node *&root) {
	if (root == NULL)return;
	clearTree(root->left);
	clearTree(root->right);
	delete root->s;
	delete root;
	root = NULL;
};
void main() {
	setlocale(LC_ALL, "rus");
	FILE *in;
	if (fopen_s(&in, "song.txt", "r") != NULL) {
		cout << " Невозможно открыть файл \n";
		system("pause");
		return;
	}
	node *root=NULL;
	root = createTree(in, root);// создание дерева из файла 
	printTree(root);// упорядоченный вывод на консоль дерева
	clearTree(root);// удаление дерева
	fclose(in);
	system("pause");
}
