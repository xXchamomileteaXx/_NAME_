#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct students
{
    string fio;
    string sex;
    int group;
    int groupN;
    int ratings[8];
    string form;
    string date;
};
//студенты с индексом i
void Show(vector<students> people, int n, int i)
{

    cout << "FIO:" << people[i].fio << "\n";
    cout << "Group number:" << people[i].group << "\n";
    cout << "Number in the group:" << people[i].groupN << "\n";
    cout << "Gender of the person:" << people[i].sex << "\n";
    cout << "Form of study:" << people[i].form << "\n";
    cout << "Rating:";
    for (int j = 0; j < 8; j++) cout << people[i].ratings[j] << " ";  cout << "\n";
    cout << "Date and time of recording:" << people[i].date << "\n\n";

}
//вывод всех студентов
void ShowStud(vector<students> people, int n)
{
    int stud;
    cout << "All students on the list\n\n";
    for (int i = 0; i < n; i++)
    {
        stud = i + 1;
        cout << "Student " << stud << "\n\n";
        cout << "FIO:" << people[i].fio << "\n";
        cout << "Group number:" << people[i].group << "\n";
        cout << "Number in the group:" << people[i].groupN << "\n";
        cout << "Gender of the person:" << people[i].sex << "\n";
        cout << "Form of study:" << people[i].form << "\n";
        cout << "Rating:";
        for (int j = 0; j < 8; j++) cout << people[i].ratings[j] << " ";  cout << "\n";
        cout << "Date and time of recording:" << people[i].date << "\n\n";
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}
//добавление студента
void Add(vector<students>& people, int& n)
{
    n++;
    people.resize(n);
    int i = n - 1;

    ofstream  fi;
    fi.open("file.txt", fstream::app);
    if (!fi.is_open())
    {
        cout << "\nFile opening error";
    }
    else {

        cout << "Enter the last name, first name and patronymic: ";
        cin.ignore();
        getline(cin, people[i].fio);
        fi << people[i].fio << "\n";

        cout << "Enter group number: ";
        cin >> people[i].group;
        fi << people[i].group << "\n";

        cout << "Enter the number in the group: ";
        cin >> people[i].groupN;
        fi << people[i].groupN << "\n";

        cout << "Enter the gender of the person: ";
        cin.ignore();
        getline(cin, people[i].sex);
        fi << people[i].sex << "\n";

        cout << "Enter the form of study: ";
        getline(cin, people[i].form);
        fi << people[i].form << "\n";

        for (int j = 0; j < 8; j++) { cout << "Enter rating: "; cin >> people[i].ratings[j]; }
        for (int j = 0; j < 8; j++) fi << people[i].ratings[j] << " ";
        fi << "\n";

        cout << "Enter the date and time of the recording: ";
        cin.ignore();
        getline(cin, people[i].date);
        fi << people[i].date << "\n";

    }

    fi.close();
    cout << "\n\nRecorded\n\n";
    system("pause");
    system("cls");
}
//запись в файл
void Recording(vector<students>& people, int& n)
{

    ofstream Rec;
    Rec.open("students.txt");
    if (!Rec.is_open())
    {
        cout << "\nFile opening error";
    }
    else {

        for (int i = 0; i < n; i++)
        {
            Rec << people[i].fio << "\n";
            Rec << people[i].group << "\n";
            Rec << people[i].groupN << "\n";
            Rec << people[i].sex << "\n";
            Rec << people[i].form << "\n";
            for (int j = 0; j < 8; j++) Rec << people[i].ratings[j] << " ";
            Rec << "\n";
            Rec << people[i].date << "\n";
        }
    }
    Rec.close();

}
//изменение определенных данных
void Change(vector<students>& people, int& n)
{
    int num, choose;
    cout << "Enter student number from 1 to " << n << "\n";
    cout << "You entered: ";
    cin >> num;
    num--;

    cout << "\nWhat needs to be changed\n\n";
    cout << "1 - the last name, first name and patronymic\n";
    cout << "2 - group number\n";
    cout << "3 - number in the group\n";
    cout << "4 - gender\n";
    cout << "5 - form of study\n";
    cout << "6 - rating\n";
    cout << "7 - date and time of the recording\n";

    cout << "\nYou entered: ";
    cin >> choose;
    cout << "\n";

    switch (choose)
    {
    case 1:
        cout << "Enter the last name, first name and patronymic: "; cin.ignore();
        getline(cin, people[num].fio);
        break;
    case 2:
        cout << "Enter group number: ";
        cin >> people[num].group;
        break;
    case 3:
        cout << "Enter the number in the group: ";
        cin >> people[num].groupN;
        break;
    case 4:
        cout << "Enter the gender of the person: "; cin.ignore();
        getline(cin, people[num].sex);
        break;
    case 5:
        cout << "Enter the form of study: "; cin.ignore();
        getline(cin, people[num].form);
        break;
    case 6:
        for (int j = 0; j < 8; j++) { cout << "Enter rating: "; cin >> people[num].ratings[j]; }
        break;
    case 7:
        cout << "Enter the date and time of the recording: "; cin.ignore();
        getline(cin, people[num].date);
        break;
    }
    Recording(people, n);
    cout << "\nData changed\n\n";
    system("pause");
    system("cls");
}
//данные студентов определенной группы
void ShowG(vector<students> people, int n)
{
    int num, check = 0;
    cout << "Enter group number";
    cout << "\nYou entered: ";
    cin >> num; cout << "\n";
    for (int i = 0; i < n; i++)
    {
        if (people[i].group == num)
        {
            Show(people, n, i);
            check = 1;
        }

    }

    if (check == 0) cout << "There is no such group";
    cout << "\n\n";
    system("pause");
    system("cls");
}
//топ 3 
void Rating(vector<students> people, int n)
{
    double* rating = new double[n];
    double max1 = 0, max2 = 0, max3 = 0, dub = 0.0;
    int top1 = 0, top2 = 0, top3 = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < 8; j++)dub += people[i].ratings[j];
        dub /= 8;

        rating[i] = dub;

        dub = 0;
    }
    for (int i = 0; i < n; i++) { if (rating[i] > max1) { max1 = rating[i]; top1 = i; } }
    for (int i = 0; i < n; i++) { if (rating[i] > max2 && people[i].fio != people[top1].fio) { max2 = rating[i]; top2 = i; } }
    for (int i = 0; i < n; i++) { if (rating[i] > max3 && people[i].fio != people[top1].fio && people[i].fio != people[top2].fio) { max3 = rating[i]; top3 = i; } }


    cout << "Top 1 with an average score: " << max1 << "\n\n";  Show(people, n, top1);
    cout << "\n\nTop 2 with an average score: " << max2 << "\n\n";  Show(people, n, top2);
    cout << "\n\nTop 3 with an average score: " << max3 << "\n\n";  Show(people, n, top3);

    delete[] rating;
    cout << "\n\n";
    system("pause");
    system("cls");
}
//количество мужчин и женщин
void MF(vector<students> people, int n)
{
    int countM = 0, countF = 0;
    for (int i = 0; i < n; i++)
    {
        if (people[i].sex == "F") countF++;
        if (people[i].sex == "M") countM++;

    }

    cout << "\n\nWomen: " << countF << "\n\n";
    cout << "Men: " << countM;

    cout << "\n\n\n";
    system("pause");
    system("cls");
}
//количество степендиатов
void Scholarship(vector<students> people, int n)
{
    int check = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
            if (people[i].ratings[j] == 3) check = 1;

        if (people[i].form == "day" && check == 0) count++;

        check = 0;
    }

    cout << "\n\nNumber of students with a scholarship: " << count << "\n\n\n";
    system("pause");
    system("cls");
}
//оценки и стипендии
void NoScholarship(vector<students> people, int n)
{
    int check = 0, count = 0, count5 = 0, count5_ = 0, count4 = 0;
    cout << "Students who do not receive a scholarship:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
            if (people[i].ratings[j] == 3) check = 1;

        if (people[i].form == "evening" || check == 1)
        {
            Show(people, n, i);
        }

        check = 0;
    }
    system("pause"); system("cls");
    cout << "Students with grades 5 and 4:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (people[i].ratings[j] == 3) check = 1;
            if (people[i].ratings[j] == 5) count5_++;
            if (people[i].ratings[j] == 4) count4++;
        }
        if (check == 0 && count5_ < 8 && count4 > 0)
        {
            Show(people, n, i);
        }
        count5_ = 0;
        check = 0;
    }
    system("pause"); system("cls");
    cout << "Excellent students:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
            if (people[i].ratings[j] == 5) count5++;

        if (count5 == 8)
        {
            Show(people, n, i);
        }
        count5 = 0;
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}
//данные студентов с определенным номером
void ShowN(vector<students> people, int n)
{
    int num, check = 0;
    cout << "Enter student number\n";
    cout << "You entered:";
    cin >> num; cout << "\n";
    for (int i = 0; i < n; i++)
    {
        if (people[i].groupN == num)
        {
            Show(people, n, i);
            check = 1;
        }

    }

    if (check == 0) cout << "There is no such number";
    cout << "\n\n";
    system("pause");
    system("cls");
}
//дата
void Time(vector<students> people, int n)
{
    string t[12] = { "12","13","14","15","16","17","18","19","20","21","22","23" };
    string t_[12] = { "00","01","02","03","04","05","06","07","08","09","10","11" };
    string sub, dub, time_; int p, check = 0;
    cout << "Enter day of week,month and day as in the file: ";
    cin.ignore();
    getline(cin, time_); cout << "\n\n";
    for (int i = 0; i < n; i++)
    {
        sub = people[i].date;
        if (sub.find_first_not_of(time_) >= 10)
        {
            Show(people, n, i);
            check = 1;
        }
    }
    if (check == 0) cout << "No notes made on this day\n";
    system("pause"); system("cls");
    cout << "Afternoon notes\n\n";
    for (int i = 0; i < n; i++)
    {
        dub = people[i].date;
        if (dub.size() >= 24) p = 11;
        else p = 10;

        for (int j = 0; j < 12; j++)
        {
            if (t[j] == dub.substr(p, 2))
            {
                Show(people, n, i);
            }
        }
    }
    system("pause"); system("cls");
    cout << "Notes made before noon\n\n";
    for (int i = 0; i < n; i++)
    {
        dub = people[i].date;
        if (dub.size() >= 24) p = 11;
        else p = 10;

        for (int j = 0; j < 12; j++)
        {
            if (t_[j] == dub.substr(p, 2))
            {
                Show(people, n, i);
            }
        }
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

int main()
{

    ifstream fin;
    fin.open("students.txt");
    int n = 0, task;
    while (!fin.eof()) {
        if (fin.get() == '\n')
            n++;
    }
    n = n / 7;// количество студентов
    fin.close();
    cout << "Number of students on the list: " << n << "\n\n";

    vector<students>people(n);

    ifstream f;
    f.open("file.txt");
    if (!f.is_open())
    {
        cout << "\nFile opening error";
    }
    else {

        for (int i = 0; i < n; i++)
        {
            getline(f, people[i].fio);
            f >> people[i].group; f.ignore();
            f >> people[i].groupN; f.ignore();
            getline(f, people[i].sex);
            getline(f, people[i].form);
            for (int j = 0; j < 8; j++) { f >> people[i].ratings[j]; }
            f.ignore(2);
            getline(f, people[i].date);

        }
    }
    f.close();

    do
    {

        cout << "Enter number of task\n\n";
        cout << "[1] Create a new student record\n";
        cout << "[2] Making changes to an existing record\n";
        cout << "[3] Display of all student data\n";
        cout << "[4] Display of information about all students of group N\n";
        cout << "[5] Finding the most successful students\n";
        cout << "[6] Display of the number of male and female students\n";
        cout << "[7] Determining the number of students who will receive the scholarship\n";
        cout << "[8] Conclusion of data on students who: do not receive a scholarship, study only for good and excellent, study only excellently\n";
        cout << "[9] Displays data about students who have a number in the list - k\n";
        cout << "[10] Displays all entries made on the day that the user enters, displays all entries made in the afternoon, displays all entries made before noon.\n";
        cout << "[0] Exit\n";
        cout << "\n";

        cout << "You entered: ";
        cin >> task;

        system("cls");

        switch (task)
        {
        case 1:
            Add(people, n);
            break;

        case 2:
            Change(people, n);
            break;

        case 3:
            ShowStud(people, n);
            break;

        case 4:
            ShowG(people, n);
            break;

        case 5:
            Rating(people, n);
            break;

        case 6:
            MF(people, n);
            break;

        case 7:
            Scholarship(people, n);
            break;

        case 8:
            NoScholarship(people, n);
            break;

        case 9:
            ShowN(people, n);
            break;

        case 10:
            Time(people, n);
            break;

        case 0:

            break;
        }

    } while (task != 0);


    return 0;
}



