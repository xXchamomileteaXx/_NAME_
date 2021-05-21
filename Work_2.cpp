#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


struct list
{
    int data;
    list* prev;
    list* next;
};

int count_ = 0;
list* head = NULL, * tail = NULL;


//поск индекса элемента num
int SerchInd_l(int num)
{
    list* t = head;
    int serch_c = 0;
    while (t) {

        if (t->data == num)
        {
            return serch_c;
            break;
        }
        t = t->next;
        serch_c++;

    }
}
//поиск элемента с индексом num
list* SerchData_l(int num)
{
    list* t = head;
    int serch_c = 0;
    while (t) {

        if (serch_c == num)
        {
            return t;
            break;
        }
        t = t->next;
        serch_c++;

    }
}

int SerchData_l3(int num)
{
    list* t = head;
    int serch_c = 0;
    while (t) {

        if (serch_c == num)
        {
            return t->data;
            break;
        }
        t = t->next;
        serch_c++;

    }
}
//заполнение списка
void Add_list(int x) {
    list* temp = new list;
    temp->data = x;
    temp->next = NULL;
    count_++;
    if (!head) {
        temp->prev = NULL;
        head = temp;
        tail = head;
    }
    else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}
//вставка элемента не в начало списка
void Add_In(list* elem, int num)
{
    list* NewEl = new list;

    NewEl->data = num;
    if (elem->next == NULL) NewEl->next = NULL;
    else  NewEl->next = elem->next;
    elem->next = NewEl;
    NewEl->prev = elem;
  

  
    if (elem->next != NULL) elem->next->prev = NewEl;
    if (NewEl->next == NULL) tail = NewEl;
}
//вставка элемента в начало списка
void First_In(int num)
{
    list* NewEl = new list;
    list* tmp = head;
    NewEl->prev = NULL;
    NewEl->next = head;
    NewEl->data = num;

    tmp->prev = NewEl;
    tmp->next = head->next;

    head = NewEl;
}
//вставка элемента
void Insert_list(int in,int ch)
{
    count_++;
    int ind, num = ch, c = 0;
     ind = in; 
    list* per = head;
  
    while (per != NULL)
    {
        if (ind == 0)
        {
            First_In(num);
            break;
        }
        if (c == ind - 1)
        {
            Add_In(per, num);
            break;
        }
        per = per->next; c++;
    }
}
//вывод списка
void Show_list() {
    list* t = head;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << "\n\n";
}
//удаление элемента по индексу
void Del_list(int x)
{
    if ((x == 0) and (head->next)) {
        list* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        count_--;
        return;
    }
    else if ((x == 0) and (head == tail)) {

        head->next = NULL;
        head = NULL;
        delete head;
        count_ = 0;
        return;
    }

    if (x == count_ - 1) {
        list* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        count_--;
        return;
    }


    list* temp = SerchData_l(x);

    list* prev_el, * next_el;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    count_--;

}
//заполнение списка 1 способом
void Fill_list1(int N)
{
    int elem;
    for (int i = 0; i < N; i++)
    {
        elem = rand() % 199 - 99;
        Add_list(elem); 
    }
}
//заполнение списка 2 способом
void Fill_list3()
{
    ifstream f;
    f.open("file.txt");
    if (!f.is_open())
    {
        cout << "\nFile opening error";
    }
    else {
        int i = 0,x;
        while (!f.eof())
        {
            f >> x;
            Add_list(x);
            i++;
        }
       
    }
    f.close();
}
//заполнение списка 3 способом
void Fill_list2()
{
    int tmp = 0;

    while (tmp != -1)
    {
        cin >> tmp;
        if (tmp == -1)return;
        Add_list(tmp);
    }
        
    system("cls");
}


//вывод массива
void Show_mas(int const* mas_dyn,int const &dyn)
{
	for (int i = 0; i < dyn; i++)
	{
		cout << mas_dyn[i] << " ";
	}

}
//заполнение массива 1 способом
void Fill_mas1(int& dyn_a, int* mas_dyn)
{

	for (int i = 0; i < dyn_a; i++)
	{
	 mas_dyn[i] = rand() % 199 - 99;
	}

}
//заполнение массива 2 способом
void Fill_mas2(int& dyn_b, int* mas_dyn)
{
    int tmp = 0;
	while (tmp != -1)
	{
        cin >> tmp;
        if (tmp == -1)return;
        mas_dyn[dyn_b] = tmp;
		dyn_b++;
	}
    system("cls");
}
//заполнение массива 3 способом
void Fill_mas3(int& dyn_c, int* mas_dyn)
{
	ifstream f;
	f.open("file.txt");
	if (!f.is_open())
	{
		cout << "\nFile opening error";
	}
	else {
		int i = 0;
		while (!f.eof())
		{
			f >> mas_dyn[i];
			i++;
		}
        dyn_c = i;
	}
	f.close();
}
//расширение массива на 1
void Resize_P(int & N, int *&mas_dyn)
{
	int N2; N2 = N + 1;
	int* mas_rez = new int[N2];  
		
	for (int i = 0; i < N2; i++)
		mas_rez[i] = mas_dyn[i];
		
	delete[] mas_dyn;
						
	
	 mas_dyn = mas_rez ;
	
}
//уменьшение массива на 1
void Resize_M(int& N, int*& mas_dyn)
{
	int N2; N2 = N - 1;
	int* mas_rez = new int[N2];

	for (int i = 0; i < N2; i++)
		mas_rez[i] = mas_dyn[i];

	delete[] mas_dyn;


	mas_dyn = mas_rez;
	N = N2;
}
//вставка элемента в массив
void Insert_mas(int& N, int*& mas_dyn,int ind,int ch)
{
	int newi = ind;int i_num = ch;	
    Resize_P(N, mas_dyn);
	

        for (int i = N - 1; i >= newi; i--)
            mas_dyn[i + 1] = mas_dyn[i];

        mas_dyn[newi] = i_num;
        N++;

}
//удаление элемента по индексу
void Del_mas(int& N, int*& mas_dyn,int del)
{
	
	for (int i = del; i < N - 1; i++)
		mas_dyn[i] = mas_dyn[i + 1];
	
    Resize_M(N, mas_dyn);

}
//поиск индекса ind элемента ch
int SerchInd_m(int N,int *dyn_mas,int ch)
{
    for (int i = 0; i < N; i++)
    {
        if (dyn_mas[i] == ch) return i;
    }
}
//поиск элемента с индексом ind
int SerchData_m(int N, int* dyn_mas, int ind)
{
    for (int i = 0; i < N; i++)
    {
        if (i == ind) return dyn_mas[i];
    }

}


void Task_fill_time1(int*& mas_dyn,int &N)
{
    auto begin_m = steady_clock::now();
    Fill_mas1(N, mas_dyn);
    auto end_m = steady_clock::now();
    auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
    Show_mas(mas_dyn, N);
    cout << "\n\nElapsed time in nanoseconds: " << elepsed_m.count() << "\n\n\n";

    auto begin_l = steady_clock::now();
    Fill_list1(N);
    auto end_l = steady_clock::now();
    auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
    Show_list();
    cout << "Elapsed time in nanoseconds: " << elepsed_l.count() << "\n";
}

void Task_fill_time2(int*& mas_dyn, int& N)
{
    
    auto fillmasB = steady_clock::now();
    Fill_mas2(N, mas_dyn);
    auto fillmasE = steady_clock::now();
    auto elepsed_mas = duration_cast<nanoseconds>(fillmasE - fillmasB);
    Show_mas(mas_dyn, N);
    cout << "\n\nElapsed time in nanoseconds: " << elepsed_mas.count() << "\n\n\n";

    auto filllistB = steady_clock::now();
    Fill_list2();
    auto filllistE = steady_clock::now();
    auto elepsed_list = duration_cast<nanoseconds>(filllistE - filllistB);
    Show_list();
    cout << "Elapsed time in nanoseconds: " << elepsed_list.count() << "\n";
}

void Task_fill_time3(int*& mas_dyn, int& N)
{
    auto begin_m = steady_clock::now();
    Fill_mas3(N, mas_dyn);
    auto end_m = steady_clock::now();
    auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
    Show_mas(mas_dyn, N);
    cout << "\n\nElapsed time in nanoseconds: " << elepsed_m.count() << "\n\n\n";

    auto begin_l = steady_clock::now();
    Fill_list3();
    auto end_l = steady_clock::now();
    auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
    Show_list();
    cout << "Elapsed time in nanoseconds: " << elepsed_l.count() << "\n";
}

void Task_insert_time(int*& mas_dyn, int& N)
{
     int ind, ch; 
     cout << "Array\n"; Show_mas(mas_dyn, N);
     cout << "\n\nEnter index to insert: "; cin >> ind;
     cout << "Enter new element: "; cin >> ch;
    auto begin_m = steady_clock::now();
    Insert_mas(N, mas_dyn, ind, ch); 
    auto end_m = steady_clock::now();
    auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
    cout << "\nArray after insertion\n"; Show_mas(mas_dyn, N);
    cout << "\n\nElapsed time in nanoseconds: " << elepsed_m.count() << "\n\n\n";

    cout << "List\n"; Show_list();
    cout << "Enter index to insert: "; cin >> ind;
    cout << "Enter new element: "; cin >> ch; cout << "\n";
    auto begin_l = steady_clock::now();
    Insert_list(ind, ch); 
    auto end_l = steady_clock::now();
    auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
    cout << "\List after insertion\n"; Show_list();
    cout << "Elapsed time in nanoseconds: " << elepsed_l.count() << "\n\n";

}

void Task_del_time(int*& mas_dyn, int& N)
{
    int ch = 0, e, pr;
    cout << "if insert in array by value enter 1 if at index enter 2\n";
    cout << "You choose: "; cin >> pr; cout << "\n\n"<<"Array\n";
    Show_mas(mas_dyn, N); cout << "\n\n";
    if (pr == 1) { cout << "Enter the item to delete: "; cin >> e; ch = SerchInd_m(N, mas_dyn, e); cout << "\n"; }
    if (pr == 2) { cout << "Enter index to delete: "; cin >> ch; cout << "\n";}

    auto begin_m = steady_clock::now();
    Del_mas(N,mas_dyn, ch);
    auto end_m = steady_clock::now();
    auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
    cout << "Array after element has been removed\n"; Show_mas(mas_dyn, N);
    cout << "\n\nElapsed time in nanoseconds: " << elepsed_m.count() << "\n\n\n";

    cout << "\nif insert in list by value enter 1 if at index enter 2\n";
    cout << "You choose: "; cin >> pr; cout << "\n" << "list\n";
    Show_list(); 
    if (pr == 1) { cout << "Enter the item to delete: "; cin >> e; ch = SerchInd_l(e); cout << "\n"; }
    if (pr == 2) { cout << "Enter index to delete: "; cin >> ch; cout << "\n";}

    auto begin_l = steady_clock::now();
    Del_list(ch);
    auto end_l = steady_clock::now();
    auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
    cout << "List after element has been removed\n"; Show_list();
    cout << "Elapsed time in nanoseconds: " << elepsed_l.count() << "\n\n";

}

void Task_find_time(int*& mas_dyn, int& N)
{
    int Find_m, Fch_m, Find_l, Fch_l, choose_;

    cout << "If you need to get the index of the entered number, press 1,if the number with a specific index, press 2\n";
    cout << "You choose: "; cin >> choose_;
    //получение числа 
    if (choose_ == 1)
    {
        cout << "\n\nArray\n";
        Show_mas(mas_dyn, N); cout << "\n\n";
        cout << "\nEnter number: "; cin >> Fch_m;
        cout << "Number index: ";
        auto begin_m = steady_clock::now();
         cout << SerchInd_m(N, mas_dyn, Fch_m);
        auto end_m = steady_clock::now();
        auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
        cout << "\n\nElapsed time in nanoseconds: " << elepsed_m.count() ;

        cout << "\n\n\nlist\n";
        Show_list(); cout << "\n";
        cout << "Enter number: "; cin >> Fch_l;
        cout << "Number with index: ";
        auto begin_l = steady_clock::now();
        cout << SerchInd_l(Fch_l);
        auto end_l = steady_clock::now();
        auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
        cout << "\n\nElapsed time in nanoseconds: " << elepsed_l.count() << "\n\n";
    }
    //получение индекса
    if (choose_ == 2)
    {
        cout << "\n\nArray\n";
        Show_mas(mas_dyn, N); cout << "\n\n";
        cout << "\nEnter index: "; cin >> Find_m;
        auto begin_m = steady_clock::now();
        cout << "Number: ";
        cout << SerchData_m(N, mas_dyn, Find_m);
        auto end_m = steady_clock::now();
        auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
        cout << "\n\nElapsed time in nanoseconds: " << elepsed_m.count() << "\n\n";

        cout << "\n\n\nlist\n";
        Show_list(); cout << "\n";
        cout << "Enter index: "; cin >> Find_l;
        cout << "Number: ";
        auto begin_l = steady_clock::now();
        cout << SerchData_l3(Find_l);
        auto end_l = steady_clock::now();
        auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
        cout << "\n\nElapsed time in nanoseconds: " << elepsed_l.count() << "\n\n";

    }



}


int main()
{
	int N = 100,fill,task;
	int* mas_dyn = new int[N];
	
    cout << "Choose a filling method for array and list\n\n";
    cout << "[1] - Enter the number of elements in the array and list, which will be automatically filled with random numbers\n";
    cout << "[2] - Enter array and list elements into the console, N is determined automatically by the number of entered elements\n";
    cout << "[3] - The array and list is read from the file, N is defined as the number of array elements in the file\n\n";
    cout << "You entered: ";
    cin >> fill; cout << "\n\n";
    system("pause"); system("cls");

    switch (fill)
    {
    case 1:
        cout << "Enter the number of items\n" << "You entered: ";   
        cin >> N; cout << "\n\n";
        Task_fill_time1(mas_dyn, N);  
        break;
    case 2:
        N = 0;
        Task_fill_time2(mas_dyn, N);
        break;
    case 3:
        Task_fill_time3(mas_dyn, N);
        break;
    }

    cout << "\n\n";

    do
    {
       
        cout << "Choose a task\n";
        cout << "[1] - Comparison of insert time\n";
        cout << "[2] - Comparison of delete time\n";
        cout << "[3] - Comparison of time of receipt\n";
        cout << "[0] - Exit\n\n";
        cout << "You entered: "; cin >> task;
        system("cls");
	  switch (task)
	  {
	  case 1:
          Task_insert_time(mas_dyn, N);
          system("pause"); system("cls");
		break;
	  case 2:
          if (count_ == 0 && N == 0) { cout << "List and array is empty"; system("pause"); system("cls"); break;}
          if (count_ == 0) { cout << "List is empty"; system("pause"); system("cls"); break;}
          if (N == 0) { cout << "Array is empty"; system("pause"); system("cls"); break;}
          Task_del_time(mas_dyn, N); 
          system("pause"); system("cls");
		break;

	  case 3:   
          Task_find_time(mas_dyn, N);
          system("pause"); system("cls");
		break;
      case 0:
          break;
	  }

    } while (task != 0);
   



    while (head) {
        tail = head->next;
        delete head;
        head = tail;
    }
	
	delete[] mas_dyn;

}

