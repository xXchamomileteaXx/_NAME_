#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <fstream>
//работа расчитана на выражения с цифрами
//пример (6+5)-4*2
using namespace std;

double Eval(char* str);
double Number(char*, unsigned*);
double Expr(char*, unsigned*);
double Term(char*, unsigned*);
double Factor(char*, unsigned*);

void ResultRP(char*);
void ResultP(char*, int);
void PrefixPolish(char*, char*);
void PostfixPolish(char*, char*);
int CheckingSimpleExpression(char*);
int CheckingRP(char*);
int CheckingP(char*);

struct stack
{
    char c;
    stack* next;
}*top;

int prior(char a)
{

    switch (a)
    {
    case '*':case'/': return 3;
    case'-':case'+': return 2;
    case'(':return 1;
    }

    return 0;
}

stack* in(stack* p, char out)
{
    stack* temp = new stack;
    temp->c = out;
    temp->next = p;

    return temp;
}

stack* out(stack* p, char& in)
{
    stack* temp = p;
    in = p->c;
    p = p->next;

    delete temp;

    return p;
}

int main()
{
    char In[90], Out[90];
    int count = 0, l = 0, choice_1, task; string file, str; ifstream fin;
    ofstream out; int GL;
    char t_a[50], t_b[50],
        t_0[] = "3+7*(2+3)/2", t_1[] = "(3+5)*2-4";


    do
    {
        cout << "Enter number of task\n\n";
        cout << "(1) Conversion of the entered expression\n\n";
        cout << "(2) Correctness check\n\n";
        cout << "(3) Calculations\n\n";
        cout << "(4) Verification work\n\n";
        cout << "(0)exit";
        cout << "\n\nYou entered: ";

        cin >> GL;
        cout << " ";

        system("cls");

        switch (GL)
        {

        case 1:

            cout << "Task one:\n\n";
            cout << "If you want transform infix to Postfix print 1\nIf you want transform infix to Prefix print 2\n\n";
            cout << "You entered: ";
            cin >> choice_1; cout << "\n";
            switch (choice_1)
            {
            case 1:
                cout << "If keyboard input press - 1 if from file - 2\n";
                cout << "You entered: ";
                cin >> task;
                if (task == 1)
                {
                    cout << "You can use a letter from 'a' to 'z' or a number from '0' to '9'\n";
                    cout << "You entered: "; cin >> In; cout << "\n";
                }
                if (task == 2)
                {
                    cout << "\nEnter a file name: ";
                    cin >> file;
                    fin.open(file);

                    if (!fin.is_open())
                    {
                        cout << "\nFile opening error";
                    }
                    else
                    {
                        while (!fin.eof())
                        {
                            fin >> In;
                            cout << "\nExpression: " << In << endl;
                        }
                    }
                    fin.close();
                }
                cout << "\nPostfixPolish: ";
                PostfixPolish(In, Out); cout << endl;
                break;
            case 2:
                cout << "If keyboard input press - 1 if from file - 2\n";
                cout << "You entered: ";
                cin >> task;
                if (task == 1)
                {
                    cout << "You can use a letter from 'a' to 'z' or a number from '0' to '9'\n";
                    cout << "You entered: "; cin >> In; cout << "\n";
                }
                if (task == 2)
                {
                    cout << "\nEnter a file name: ";
                    cin >> file;
                    fin.open(file);

                    if (!fin.is_open())
                    {
                        cout << "\nFile opening error";
                    }
                    else
                    {
                        while (!fin.eof())
                        {
                            fin >> In;
                            cout << "\nExpression: " << In << endl;
                        }
                    }
                    fin.close();
                }
                cout << "\nPrefixPolish: ";
                PrefixPolish(In, Out); cout << endl;
                break;
            }

            cout << "\n\n";
            system("pause"); system("cls");
            break;

        case 2:

            cout << "\n\nTask two:\n\n";
            cout << "If you want to check the infix expression press 1\nIf you want to check the PostfixPolish expression press 2\nIf you want to check the PrefixPolish expression press 3\n\n";
            cout << "You entered: ";
            cin >> task; cout << endl;
            switch (task)
            {
            case 1:
                cout << "If keyboard input press - 1 if from file - 2\n";
                cout << "You entered: ";
                cin >> task;
                if (task == 1)
                {
                    cout << "You can use a number from '0' to '9'\n";
                    cout << "You entered: "; cin >> In; cout << "\n";
                }
                if (task == 2)
                {
                    cout << "\nEnter a file name: ";
                    cin >> file;
                    fin.open(file);

                    if (!fin.is_open())
                    {
                        cout << "\nFile opening error";
                    }
                    else
                    {
                        while (!fin.eof())
                        {
                            fin >> In;
                            cout << "\nExpression: " << In << endl;
                        }
                    }
                    fin.close();
                }
                CheckingSimpleExpression(In);
                break;
            case 2:
                cout << "If keyboard input press - 1 if from file - 2\n";
                cout << "You entered: ";
                cin >> task;
                if (task == 1)
                {
                    cout << "You can use a number from '0' to '9'\n";
                    cout << "You entered: "; cin >> In; cout << "\n";
                }
                if (task == 2)
                {
                    cout << "\nEnter a file name: ";
                    cin >> file;
                    fin.open(file);

                    if (!fin.is_open())
                    {
                        cout << "\nFile opening error";
                    }
                    else
                    {
                        while (!fin.eof())
                        {
                            fin >> In;
                            cout << "\nExpression: " << In << endl;
                        }
                    }
                    fin.close();
                }
                CheckingRP(In);
                break;
            case 3:
                cout << "If keyboard input press - 1 if from file - 2\n";
                cout << "You entered: ";
                cin >> task;
                if (task == 1)
                {
                    cout << "You can use a number from '0' to '9'\n";
                    cout << "You entered: "; cin >> In; cout << "\n";
                }
                if (task == 2)
                {
                    cout << "\nEnter a file name: ";
                    cin >> file;
                    fin.open(file);

                    if (!fin.is_open())
                    {
                        cout << "\nFile opening error";
                    }
                    else
                    {
                        while (!fin.eof())
                        {
                            fin >> In;
                            cout << "\nExpression: " << In << endl;
                        }
                    }
                    fin.close();
                }
                CheckingP(In);
                break;
            }

            cout << "\n\n";
            system("pause"); system("cls");
            break;

        case 3:

            cout << "Task three:\n\n";
            cout << "If you want infix to calculating a simple expression print 1\nIf you want calculating a Postfix polish print 2\nIf you want calculating a Prefix polish print 3";
            cout << "\nYou entered: ";
            cin >> choice_1; cout << "\n";
            switch (choice_1)
            {
            case 1:
                cout << "If keyboard input press - 1 if from file - 2\n";
                cout << "You entered: ";
                cin >> task;
                if (task == 1)
                {
                    cout << "You can use a number from '0' to '9'\n";
                    cout << "You entered: "; cin >> In; cout << "\n";
                }
                if (task == 2)
                {
                    cout << "\nEnter a file name: ";
                    cin >> file;
                    fin.open(file);

                    if (!fin.is_open())
                    {
                        cout << "\nFile opening error";
                    }
                    else
                    {
                        while (!fin.eof())
                        {
                            fin >> In;
                            cout << "\nExpression: " << In << endl;
                        }
                    }
                    fin.close();
                }
                cout << "\n\nResult: "; cout << Eval(In);
                break;
            case 2:
                cout << "If keyboard input press - 1 if from file - 2\n";
                cout << "You entered: ";
                cin >> task;
                if (task == 1)
                {
                    cout << "You can use a number from '0' to '9'\n";
                    cout << "You entered: "; cin >> In; cout << "\n";
                }
                if (task == 2)
                {
                    cout << "\nEnter a file name: ";
                    cin >> file;
                    fin.open(file);

                    if (!fin.is_open())
                    {
                        cout << "\nFile opening error";
                    }
                    else
                    {
                        while (!fin.eof())
                        {
                            fin >> In;
                            cout << "\nExpression: " << In << endl;
                        }
                    }
                    fin.close();
                }
                cout << "\n\nResult: "; ResultRP(In);
                break;
            case 3:
                cout << "If keyboard input press - 1 if from file - 2\n";
                cout << "You entered: ";
                cin >> task;
                if (task == 1)
                {
                    cout << "You can use a number from '0' to '9'\n";
                    cout << "You entered: "; cin >> In; cout << "\n";
                }
                if (task == 2)
                {
                    cout << "\nEnter a file name: ";
                    cin >> file;
                    fin.open(file);

                    if (!fin.is_open())
                    {
                        cout << "\nFile opening error";
                    }
                    else
                    {
                        while (!fin.eof())
                        {
                            fin >> In;
                            cout << "\nExpression: " << In << endl;
                        }
                    }
                    fin.close();
                }
                int len = strlen(In) - 1;
                cout << "\n\nResult: "; ResultP(In, len);
                break;
            }

            cout << "\n\n";
            system("pause"); system("cls");
            break;

        case 4:

            cout << "Task four:\n\n";
            cout << "Postfix notation - 1 Prefix notation - 2\n";
            cout << "You entered: ";
            cin >> choice_1;
            switch (choice_1)
            {
            case 1:
                cout << "Translate to postfix notation: " << t_0 << "\n";
                cout << "Your answer: "; cin >> t_a; cout << "\n";
                PostfixPolish(t_0, t_b);

                out.open("answer.txt");
                if (out.is_open())
                {
                    out << "Postfix notation: ";
                    out << "3723+*2/+\n\n";
                    out << "3 number to the output line\n";
                    out << "+ operator on the stack (the stack was empty)\n";
                    out << "7 number to the output line\n";
                    out << "* operator on the stack (prior 3)\n";
                    out << "( on the stack(prior 1)\n";
                    out << "2 number to the output line\n";
                    out << "+ operator on the stack (prior 2)\n";
                    out << ") push from the stack to the input line to (\n";
                    out << "Output(3723+)\n";
                    out << "/ operator on the stack (prior 3 = prior 3)\n";
                    out << "Output(3723+*)\n";
                    out << "2 number to the output line\n";
                    out << "whatever is left on the stack (/) to the output line\n";
                }
                out.close();
                cout << "\n\nThe explanation is written in the file";
                break;
            case 2:
                cout << "Translate to prefix notation: " << t_1 << "\n";
                cout << "Your answer: "; cin >> t_a; cout << "\n";
                PrefixPolish(t_1, t_b);

                out.open("answer.txt");
                if (out.is_open())
                {
                    out << "Prefix notation: ";
                    out << "-*+3524\n\n";
                    out << "4 number to the output line\n";
                    out << "- operator on the stack (the stack was empty)\n";
                    out << "2 number to the output line\n";
                    out << "* operator on the stack (prior 3)\n";
                    out << ") on the stack(prior 1)\n";
                    out << "5 number to the output line\n";
                    out << "3 number to the output line\n";
                    out << "( push from the stack to the input line to )\n";
                    out << "whatever is left on the stack (-*) to the output line\n";
                }
                out.close();
                cout << "\n\nThe explanation is written in the file";
                break;
            }
            cout << "\n\n";
            system("pause"); system("cls");
            break;
        }


    } while (GL != 0);
}

void ResultRP(char* str)
{

    int i, count = 0; double st; char stt[100];
    char ss, ss1, ss2, ssr = 'z' + 1;
    double op1, op2, res = 0, mas[200];

    for (i = 0; str[i] != '\0'; ++i)
    {
        ss = str[i];

        if (ss >= 'a' && ss <= 'z')
        {
            cout << "\n" << ss << "=";
            cin >> mas[int(ss)];
        }

        if (ss >= '0' && ss <= '9')
        {
            stt[count++] = ss;
            st = atoi(stt);
            mas[int(ss)] = st;
        }
        count = 0;
    }

    for (i = 0; str[i] != '\0'; ++i)
    {
        ss = str[i];

        if (!(ss == '+' || ss == '-' || ss == '*' || ss == '/'))
            top = in(top, ss);
        else
        {
            top = out(top, ss2);

            top = out(top, ss1);

            op2 = mas[int(ss2)];

            op1 = mas[int(ss1)];

            switch (ss)
            {
            case '+': res = op1 + op2; break;

            case '-': res = op1 - op2; break;

            case '*': res = op1 * op2; break;

            case '/': res = op1 / op2; break;
            }

            mas[int(ssr)] = res;
            top = in(top, ssr);
            ssr++;
        }


    }
    cout << fixed << setprecision(2) << res;
}
void ResultP(char* dop, int len)
{
    char str[90]; int l = 0;
    for (int i = len; i >= 0; i--)
        str[l++] = dop[i];
    str[len + 1] = '\0'; cout << str;
    int i, count = 0; double st; char stt[100];
    char ss, ss1, ss2, ssr = 'z' + 1;
    double op1, op2, res = 0, mas[200];

    for (i = 0; str[i] != '\0'; ++i)
    {
        ss = str[i];
        cout << "\n";
        if (ss >= 'a' && ss <= 'z')
        {
            cout << ss << "=";
            cin >> mas[int(ss)];
        }
        else {
            stt[count++] = ss;
            st = atoi(stt);
            mas[int(ss)] = st;
        }
        count = 0;
    }

    for (i = 0; str[i] != '\0'; ++i)
    {
        ss = str[i];

        if (!(ss == '+' || ss == '-' || ss == '*' || ss == '/'))
            top = in(top, ss);
        else
        {
            top = out(top, ss2);

            top = out(top, ss1);

            op2 = mas[int(ss2)];

            op1 = mas[int(ss1)];

            switch (ss)
            {
            case '+': res = op2 + op1; break;

            case '-': res = op2 - op1; break;

            case '*': res = op2 * op1; break;

            case '/': res = op2 / op1; break;
            }

            mas[int(ssr)] = res;
            top = in(top, ssr);
            ssr++;
        }


    }
    cout << fixed << setprecision(2) << res;

}
void PrefixPolish(char* In, char* Out)
{
    stack* t, * op = NULL;
    char a;
    int k, pos, l = 0, kol = 0, kl = 0, count = 0;
    k = strlen(In) - 1; pos = k;

    while (k != -1)
    {

        if (In[k] == '(' || In[k] == ')') count++;

        if ((In[k] >= 'a' && In[k] <= 'z') || (In[k] >= '0' && In[k] <= '9'))
        {


            Out[l++] = In[k];
        }

        if (In[k] == ')')
            op = in(op, In[k]);

        if (In[k] == '(')
        {
            while ((op->c) != ')')
            {
                op = out(op, a);

                if (!op)
                    a = '\0';

                Out[l++] = a;
            }

            t = op;
            op = op->next;
            delete t;
        }

        if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/')
        {
            while (op != NULL && prior(op->c) > prior(In[k]))
            {
                op = out(op, a);
                Out[l++] = a;
            }

            op = in(op, In[k]);
        }
        k--;

    }

    while (op != NULL)
    {

        op = out(op, a);

        Out[l++] = a;

    }

    Out[l] = '\0';

    for (int j = pos - count; j >= 0; j--)
        cout << Out[j];

}
void PostfixPolish(char* In, char* Out)
{
    stack* t, * op = NULL;
    int k = 0, l = 0; char a;

    while (In[k] != '\0')
    {
        if ((In[k] >= 'a' && In[k] <= 'z') || (In[k] >= '0' && In[k] <= '9'))
            Out[l++] = In[k];

        if (In[k] == '(')
            op = in(op, In[k]);

        if (In[k] == ')')
        {
            while ((op->c) != '(')
            {
                op = out(op, a);

                if (!op)
                    a = '\0';

                Out[l++] = a;
            }

            t = op;
            op = op->next;
            delete t;
        }

        if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/')
        {
            while (op != NULL && prior(op->c) >= prior(In[k]))
            {
                op = out(op, a);
                Out[l++] = a;
            }

            op = in(op, In[k]);
        }

        k++;
    }

    while (op != NULL)
    {

        op = out(op, a);

        Out[l++] = a;

    }

    Out[l] = '\0';
    for (int i = 0; i < strlen(Out); i++)
        cout << Out[i];
}
int CheckingSimpleExpression(char* in)
{
    bool check = true;

    if (in[0] == '+' || in[0] == '*' || in[0] == '/') {
        check = false;
    }
    else if (in[strlen(in) - 1] == '+' || in[strlen(in) - 1] == '-' || in[strlen(in) - 1] == '*' || in[strlen(in) - 1] == '/') {
        check = false;
    }
    else {
        for (int i = 0; (i < strlen(in)); i++) {
            if ((in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/') && (in[i + 1] == '+' || in[i + 1] == '*' || in[i + 1] == '/')) {
                check = false;
            }
            if ((in[i] == '/') && (in[i + 1] == '0')) {
                check = false;
            }
        }
    }
    if (check != false) {
        for (int i = 0; i < strlen(in); i++)
            if (in[i] == '(' && i != 0)
                if (in[i - 1] != '+' && in[i - 1] != '-' && in[i - 1] != '*' && in[i - 1] != '/')
                    check = false;

        for (int i = 0; i < strlen(in); i++)
            if (in[i] == ')' && i != strlen(in) - 1)
                if (in[i + 1] != '+' && in[i + 1] != '-' && in[i + 1] != '*' && in[i + 1] != '/')
                    check = false;
    }

    if (check) { cout << "\nExpression is correct"; return 1; }
    else { cout << "\nExpression is not correct"; return 0; }
}
int CheckingRP(char* in)
{
    bool check = true;
    if (in[0] == '+' || in[0] == '-' || in[0] == '*' || in[0] == '/') {
        cout << "\nOperation cannot be at the beginning of a postfix record\n";
        check = false;
    }

    for (int i = 0; (i < strlen(in)); i++)
    {
        if ((in[i] != '+' && in[i] != '-' && in[i] != '*' && in[i] != '/') && !(in[i] >= 'a' && in[i] <= 'z') && !(in[i] >= '0' && in[i] <= '9')) {
            cout << "\nInvalid character entered\n";
            check = false; break;
        }
    }

    if (check) { cout << "\nExpression is correct"; return 1; }
    else { cout << "\nExpression is not correct"; return 0; }
}
int CheckingP(char* in)
{
    bool check = true;
    if (in[strlen(in) - 1] == '+' || in[strlen(in) - 1] == '-' || in[strlen(in) - 1] == '*' || in[strlen(in) - 1] == '/') {
        cout << "\nOperation cannot end in prefix notation\n";
        check = false;
    }

    for (int i = 0; (i < strlen(in)); i++)
    {
        if ((in[i] != '+' && in[i] != '-' && in[i] != '*' && in[i] != '/') && !(in[i] >= 'a' && in[i] <= 'z') && !(in[i] >= '0' && in[i] <= '9')) {
            cout << "\nInvalid character entered\n";
            check = false; break;
        }
    }

    if (check) { cout << "\nExpression is correct"; return 1; }
    else { cout << "\nExpression is not correct"; return 0; }


}


double Eval(char* str)
{
    unsigned i = 0;

    return Expr(str, &i);
}
double Number(char* str, unsigned* idx)
{
    double result = 0.0;
    double div = 10.0;
    int sign = 1;

    if (str[*idx] == '-')
    {
        sign = -1;
        ++* idx;
    }

    while (str[*idx] >= '0' && str[*idx] <= '9')
    {
        result = result * 10.0 + (str[*idx] - '0');

        ++* idx;
    }

    if (str[*idx] == '.')
    {
        ++* idx;

        while (str[*idx] >= '0' && str[*idx] <= '9')
        {
            result = result + (str[*idx] - '0') / div;
            div *= 10.0;

            ++* idx;
        }
    }

    return sign * result;
}
double Expr(char* str, unsigned* idx)
{
    double result = Term(str, idx);

    while (str[*idx] == '+' || str[*idx] == '-')
    {
        switch (str[*idx])
        {
        case '+':
            ++ * idx;

            result += Term(str, idx);

            break;
        case '-':
            ++ * idx;

            result -= Term(str, idx);

            break;
        }
    }

    return result;
}
double Term(char* str, unsigned* idx)
{
    double result = Factor(str, idx);
    double div;

    while (str[*idx] == '*' || str[*idx] == '/')
    {
        switch (str[*idx])
        {
        case '*':
            ++ * idx;

            result *= Factor(str, idx);

            break;
        case '/':
            ++ * idx;

            div = Factor(str, idx);

            if (div != 0.0)
            {
                result /= div;
            }
            else
            {
                cout << "Division by zero!\n";
                exit(-1);
            }

            break;
        }
    }

    return result;
}
double Factor(char* str, unsigned* idx)
{
    double result;
    int sign = 1;

    if (str[*idx] == '-')
    {
        sign = -1;

        ++* idx;
    }

    if (str[*idx] == '(')
    {
        ++* idx;

        result = Expr(str, idx);

        if (str[*idx] != ')')
        {
            cout << "Brackets unbalanced!\n";
            exit(-2);
        }

        ++* idx;
    }
    else
        result = Number(str, idx);



    return sign * result;
}


