#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std::chrono;
using namespace std;


//для очереди
struct node {
	const void* ptr;
	struct node* next;
};
struct queue {
	node* head;
	node* tail;
};
//Структура для дерева
struct tree {
	int data;
	tree* left;
	tree* right;
};

//функции для реализации очереди
void queueInit(queue* q) {

	q->head = q->tail = NULL;
}
int queueEmpty(queue* q) {

	return (q->head == NULL);
}
const void* queueFront(queue* q) {

	return q->head->ptr;
}

//добавление в очередь
int queuePush(queue* q, const void* ptr) {

	node* p = (node*)malloc(sizeof(node));

	if (p != NULL) {

		p->ptr = ptr;

		p->next = NULL;

		if (q->head == NULL)

			q->head = q->tail = p;

		else {

			q->tail->next = p;

			q->tail = p;
		}
	}
	return (p != NULL);
}
//удаление из очереди
void queuePop(queue* q) {

	node* t;

	if (q->head != NULL) {

		t = q->head;

		q->head = q->head->next;

		free(t);

		if (q->head == NULL)

			q->tail = NULL;
	}
}


//вывод дерева
void print(tree* branch, int g = 0, int v = 0) {
	if (!branch) {
		return;
	}
	print(branch->right, g + 1, -1);
	for (int i = 0; i != g; i++) {
		cout << "     ";
	}
	if (v == -1) {
		cout << ".- ->" << branch->data << '\n';
	}
	else if (v == 1) {
		cout << "`- ->" << branch->data << '\n';
	}
	else {
		cout << "|- ->" << branch->data << '\n';
	}
	print(branch->left, g + 1, 1);
}
//запись дерева в файл
void printRec(ofstream* Rec, tree* branch, int g = 0, int v = 0) {
	if (!branch) {
		return;
	}
	printRec(Rec, branch->right, g + 1, 6);
	for (int i = 0; i != g; i++) {
		*Rec << "    ";
	}
	if (v == 6) {
		*Rec << ".- -> " << branch->data << '\n';
	}
	else if (v == 9) {
		*Rec << "\`- ->" << branch->data << '\n';
	}
	else {
		*Rec << "|- ->" << branch->data << '\n';
	}
	printRec(Rec, branch->left, g + 1, 9);
}
//для создания дерева
void add(int el, tree*& branch) {

	if (!branch) {
		branch = new tree;

		branch->data = el;
		branch->left = 0;
		branch->right = 0;

		return;

	}
	else if (branch->data > el) {

		add(el, branch->left);
	}
	else {

		add(el, branch->right);
	};
}
//прямой обход
void straight(tree*& branch)
{

	if (NULL == branch) return; 

	cout << branch->data << " "; 

	straight(branch->left);

	straight(branch->right); 

}
//обратный обход
void back(tree*& branch) {

	if (NULL == branch) return; 

	back(branch->left); 

	back(branch->right); 

	cout << branch->data << " "; 
}
//обход в ширину
void width(const tree* tr) {

	const tree* p;
	queue q;

	queueInit(&q);
	queuePush(&q, tr);

	while (!queueEmpty(&q)) {

		p = (const tree*)queueFront(&q);

		queuePop(&q);

		cout << p->data << " ";

		if (p->left != NULL)
			queuePush(&q, p->left);

		if (p->right != NULL)
			queuePush(&q, p->right);
	}
}
//вставка элемента
void addElem(int el, tree*& branch) {

	if (!branch) {

		branch = new tree;
		branch->data = el;
		branch->left = 0;
		branch->right = 0;

		return;
	}

	else {
		if (el < branch->data) {

			addElem(el, branch->left);

		}
		else if (el > branch->data) {

			addElem(el, branch->right);
		}
	}
}
//удаление дерева
void freeTree(tree*& branch) {

	if (!branch) return;

	freeTree(branch->left);
	freeTree(branch->right);

	delete branch;
	return;
}
//удаление элемента
tree* delElem(tree*& branch, int el) {

	if (branch == NULL)
		return branch;

	if (el == branch->data) {
		tree* tmp;

		if (branch->right == NULL)
			tmp = branch->left;

		else {
			tree* ptr = branch->right;

			if (ptr->left == NULL) {

				ptr->left = branch->left;
				tmp = ptr;
			}

			else {
				tree* pmin = ptr->left;

				while (pmin->left != NULL) {

					ptr = pmin;
					pmin = ptr->left;

				}

				ptr->left = pmin->right;
				pmin->left = branch->left;
				pmin->right = branch->right;

				tmp = pmin;
			}

		}
		delete branch;
		return tmp;

	}
	else if (el < branch->data)
		branch->left = delElem(branch->left, el);
	else
		branch->right = delElem(branch->right, el);

	return branch;

}
//заполнение дерева через файл
void fillFile(tree*& Root, string name, int& N)
{
	int el;
	ifstream f_(name);
	ifstream f(name);

	if (!f_ || !f)
	{
		cout << "\nFile opening error";
	}
	else {

		while (!f_.eof()) {

			if (f_.get() == ' ')
				N++;
		}
		N++;

		cout << "Elements: ";
		for (int i = 0; i < N; i++) {
			f >> el;
			cout << el << " ";
			add(el, Root);
		}

	}
	f_.close();
	f.close();
}
//заполнение рандомными числами
void fillRandom(tree*& Root, int& vel)
{
	
	int SE;
	cout << "Elements: ";
	for (int i = 0; i < vel; i++) {

		SE = rand() % 199 - 99;
		cout << SE << " ";
		add(SE, Root);

	}
	cout << "\n\n";
}
//заполнение введенными числами
void fillX(tree*& Root, int& vel)
{
	cout << "Enter values,if you have finished typing press 666";
	char tmp = ' '; int tm;
	while (tmp != 'x')
	{
		cin >> tm; 
		if (tm == 666)return;
		add(tm, Root);
		vel++;
	}
}
//поиск элемента в дереве
tree* find(tree* Root, int el)
{
	if (Root == 0) {
		return 0;
	}
	if (Root->data == el) {
		return Root;
	}

	if (el <= Root->data) {

		if (Root->left != 0)
			return find(Root->left, el);
		else {
			return 0;
		}
	}
	else {
		if (Root->right)
			return find(Root->right, el);
		else {
			return 0;
		}
	}
}

//функции заданий
void time(tree*& Root)
{
	int el;
	cout << "Tree\n\n";
	print(Root);
	cout << "\n-----------------------------------------------\n";
	cout << "[1]\n\n";
	cout << "Enter the element you want to insert: ";
	cin >> el;
	auto begin_v = steady_clock::now();
	addElem(el, Root);
	auto end_v = steady_clock::now();
	auto elepsed_v = duration_cast<nanoseconds>(end_v - begin_v);
	cout << "Elapsed time in nanoseconds: " << elepsed_v.count() << "\n\n";
	cout << "Tree after element insertion\n\n";
	print(Root); cout << "\n\n";
	cout << "-----------------------------------------------\n";
	cout << "[2]\n\n";
	cout << "Enter the element you want to remove: ";
	cin >> el;
	if (find(Root, el)) {
		auto begin_d = steady_clock::now();
		Root = delElem(Root, el);
		auto end_d = steady_clock::now();
		auto elepsed_d = duration_cast<nanoseconds>(end_d - begin_d);
		cout << "Elapsed time in nanoseconds: " << elepsed_d.count() << "\n\n";
		cout << "Tree after element has been removed\n\n";
		print(Root);
	}
	else {
		cout << " Item not found\n";
	}
	cout << "\n-----------------------------------------------\n";
	cout << "[3]\n\n";
	cout << "Enter the element you want find: ";
	cin >> el;
	if (find(Root, el)) {
		auto begin_i = steady_clock::now();
		find(Root, el);
		auto end_i = steady_clock::now();
		auto elepsed_i = duration_cast<nanoseconds>(end_i - begin_i);
		cout << "Elapsed time in nanoseconds: " << elepsed_i.count() << "\n\n";
	}
	else {
		auto begin_i = steady_clock::now();
		find(Root, el);
		auto end_i = steady_clock::now();
		auto elepsed_i = duration_cast<nanoseconds>(end_i - begin_i);
		cout << "Item not found\n";
		cout << "Elapsed time in nanoseconds: " << elepsed_i.count() << "\n\n";
	}
	cout << "-----------------------------------------------\n\n";
}
void bypass(tree* Root)
{
	cout << "Tree\n\n";
	print(Root);
	cout << "\n-----------------------------------------------\n";
	cout << "straight: ";
	straight(Root);
	cout << "\n\n";
	cout << "back: ";
	back(Root);
	cout << "\n\n";
	cout << "width: ";
	width(Root);
	cout << "\n-----------------------------------------------\n\n\n";
}
void taskBin() {

	tree* root; int var, size, elem;


	cout << '\n' << "Enter number of variants: ";
	cin >> var;

	ofstream output_task("output_task.txt");
	ofstream output_key("output_key.txt");
	ofstream output_ans("output_ans.txt");

	if (!output_task || !output_key || !output_ans) {
		cout << "\nFile opening error\n";
		return;
	}
	for (int i = 0; i != var; i++) {
		root = 0;

		output_task << "\n\nTask [" << i + 1 << "]\n";
		output_task << "1)Create binary tree from elements: ";

		output_ans << "Task [" << i + 1 << "]\n";
		output_ans << "-Creating a binary tree-\n";
		output_ans << "                        \n" << "root\n" << "--------\n\n";

		output_key << "\n\n                                       " << "Task [" << i + 1 << "]\n\n\n";

		srand(time(0));
		size = rand() % 8 + 7;
		for (int j = 0; j != size; j++) {
			elem = rand() % 199 - 99;

			output_task << elem << " ";

			add(elem, root);
			printRec(&output_ans, root);

			output_ans << "\nstep: " << j + 1 << "\n--------" << "\n\n";
		}

		output_key << "Tree\n" << "----\n";
		printRec(&output_key, root);

		elem = rand() % 199 - 99;
		output_task << "\n2)Add element " << elem << '\n';
		addElem(elem, root);

		output_ans << "Remove element " << elem << "\n\n";
		printRec(&output_ans, root);

		output_ans << "-----------------------------------------------" << '\n';
		output_key << "\n\nTree after adding element " << elem << "\n----------------------------\n\n";
		printRec(&output_key, root);

		elem = rand() % 199 - 99;
		output_task << "3)Remove element " << elem << '\n' << '\n';
		if (find(root, elem)) {
			output_ans << "Remove element\n\n";
			root = delElem(root, elem);
			printRec(&output_ans, root);
		}
		else {
			output_ans << "\nItem not found\n\n";
		}
		output_key << "\n\nTree after element has been removed " << elem << "\n--------------------------------------\n\n";
		printRec(&output_key, root);
		freeTree(root);
	}
	output_task.close();
	output_ans.close();
	output_key.close();
}



int main() {
	ofstream tree_, Re; int task, task_;
	tree* Root = 0;
	string name;
	vector <int> file, vec;
	int vel = 0, element;// количество элементов,элемент

	do {
		cout << "Choose a filling method\n\n";
		cout << "[1] - Creation from random numbers\n";
		cout << "[2] - Elements are read from file\n";
		cout << "[3] - Enters array elements into the console\n\n";
		cout << "You choosed: ";
		cin >> task_;
		switch (task_)
		{
		case 1:
			cout << "Enter the number of elements: ";
			cin >> vel;	cout << "\n";
			fillRandom(Root, vel);
			cout << "\n";
			print(Root);
			cout << "\n\n";
			task_ = 0;
			system("pause"); system("cls");
			break;
		case 2:
			cout << "Enter the file name (with filename extension): ";
			cin >> name;
			fillFile(Root, name, vel);
			cout << "\n\n\n";
			print(Root);
			cout << "\n\n";
			task_ = 0;
			system("pause"); system("cls");
			break;

		case 3:
			fillX(Root, vel);
			task_ = 0;
			system("pause"); system("cls");
			break;
		default:
			system("cls");
			cout << "\nYou entered an incorrect value, please try again\n\n";
			task = 1;
			system("pause"); system("cls");
			break;
		}

	} while (task_ != 0);
	do
	{

		cout << "Choose a task\n";
		cout << "[1] - Console output and tree file of the binary tree\n";
		cout << "[2] - Insertion, deletion and retrieval of a tree element\n";
		cout << "[3] - Forward traversal, reverse traversal, and breadth-first traversal\n";
		cout << "[4] - Generation of tasks for practical work on binary trees\n";
		cout << "[0] - Exit\n\n";
		cout << "You entered: "; cin >> task;
		system("cls");
		switch (task)
		{
		case 1:

			Re.open("tree.txt", ios::out);
			Re.close();//для очистки содержимого в файле

			tree_.open("tree.txt", ios::app);
			if (!tree_.is_open())
			{
				cout << "\nFile opening error";
			}
			else {

				tree_ << "Binary tree:\n\n";
				printRec(&tree_, Root);
			}
			tree_.close();

			cout << "The tree recorded to the file 'tree'\n\n";
			cout << "Binary tree:\n\n";
			print(Root);

			cout << "\n\n";
			system("pause"); system("cls");
			break;
		case 2:
			time(Root);
			system("pause"); system("cls");
			break;

		case 3:
			bypass(Root);
			system("pause"); system("cls");
			break;
		case 4:
			taskBin();
			system("pause"); system("cls");
			break;
		case 0:
			break;
		default:
			system("cls");
			cout << "\nYou entered an incorrect value, please try again\n\n";
			system("pause"); system("cls");
			break;
		}

	} while (task != 0);





	freeTree(Root);

	return 0;

}