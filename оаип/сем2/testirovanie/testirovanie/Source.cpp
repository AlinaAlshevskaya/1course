#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct Uzel// ��� ���� ������
{
    char Key; // ������
    Uzel* Left; // ��������� �� ����� ���������
    Uzel* Right; // ��������� �� ������ ���������
};


struct zveno// ��� ����� �����
{
    Uzel* Element; // ����
    zveno* Sled; // ��������� �� ��������� ����� � �����
};


class Tree
{
private:
    Uzel* Root; // ������ ������
    zveno* Stack; // ���� ��� ���������� �������� �����
public:
    // ����������� ������ Tree
    Tree();
    void Udalenie(Uzel**); // ������� ��� �������� ���� �� �����
    void V_stack(Uzel*);  // ������� ��� ���������� ���� � ����
    void PrintTree(Uzel*, int); // ������� ��� ������ ������ �� �����
    void Print_Tree_Left(Uzel*, int);// ������� ��� �������������� ������ ������
    void Print_Tree_End(Uzel*, int);// ������� ��� ��������� ������ ������
    void Print_Tree_Back(Uzel*, int);// ������� ��� ��������������� ������ ������

    // ������ ��� ��������� ����� ������
    Uzel* GetTree() { return Root; };
};


void Tree::V_stack(Uzel* Elem)
{
    
    zveno* q = new (zveno);
    q->Element = Elem;
    q->Sled = Stack; // ������������� ������ �� ��������� �����
    Stack = q; // ��������� ��������� �� ������� �����
}

void Tree::Udalenie(Uzel** tmp)
{

    if (Stack != NULL)
    {
        (*tmp) = Stack->Element; // ��������� ���� ����� ���������
        zveno* q = Stack; // ���������  ��������� �� ��������� �����
        Stack = Stack->Sled; // ��������� ��������� �� ������� �����
        delete q; // ����������� ������
    }
}

void Tree::PrintTree(Uzel* w, int l)//����� ��p��� �� ��p�� 
{
   
    if (w != NULL)
    {
        PrintTree(w->Right, l + 1); // ������� ������� ���������
        for (int i = 1; i <= l; i++) cout << "   "; 
        cout << w->Key << endl; // ������� ���� ����
        PrintTree(w->Left, l + 1); // ������� ����� ���������
    }
}

void Tree::Print_Tree_Left(Uzel* w, int l)//�������p����� ����� ����p���� ������
{
    
    if (w != NULL)
    {
        cout << w->Key << " "; // ������� ���� ����
        Print_Tree_Left(w->Left, l + 1); // ����� ����� ���������
        Print_Tree_Left(w->Right, l + 1); // ����� ������ ���������
    }
}

void Tree::Print_Tree_End(Uzel* w, int l)//�������� ����� ����p���� ��p���
{
    // �������� ����� ������
    if (w != NULL)
    {
        Print_Tree_End(w->Left, l + 1); // ������� ����� ���������
        Print_Tree_End(w->Right, l + 1); // ������� ������ ���������
        cout << w->Key << " "; // ������� ���� ����
    }
}

void Tree::Print_Tree_Back(Uzel* w, int l) //��p����� ����� ����p���� ��p���
{
   
    if (w != NULL)
    {
        cout << "("; 
        Print_Tree_Back(w->Left, l + 1); // ������� ����� ���������
        cout << w->Key << " "; // ������� ���� ����
        Print_Tree_Back(w->Right, l + 1); // ������� ������ ���������
        cout << ")"; 
    }
}


Tree::Tree()
{
    Stack = NULL; // ������� ��������� ����
    Root = new (Uzel); // ������� �������� ����
    Root->Right = NULL; // �������������� ������ ��������� ��������� ����
}
void main()
{
    setlocale(LC_ALL, "Rus");
    char Formula_Post[30];
    char k; //��������������� ��p�������.
    Uzel* Ukazatel = NULL;

    cout << "������� ��p����, ���������� � ����������� ��p��... \n";
    gets_s(Formula_Post);
    _strrev(Formula_Post);
    cout << "�p������� � ����p����� ��p���-��p����...\n";

    Tree A;
    Uzel* Temp = A.GetTree(); //������� ���������.
    //��p��p������ ��p��� ������ � ����� ��� �� ��p��.
    for (int i = 0; i < strlen(Formula_Post); i++)
    {
        k = Formula_Post[i];
        //��p������ � ������� ������� k.
        if (strchr("+-*/^", k) != NULL)
        { //������ - ���p����.
            if (Temp->Right == NULL) //����������� �p���� ����.
            {
                //����p��p������ ����� ��� ������������ ����.
                Temp->Right = new (Uzel);
                // ��������� ��������� �� ����������� ����.
                Temp = Temp->Right;
                //������������� ������������ ����.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                //������ �� �p�������� ���� --> ����.
                A.V_stack(Temp);
            }
            else //���� �p���� ����.
            { //����p��p������ ����� ��� ������������ ����.
                Temp->Left = new (Uzel);
                // ��������� ��������� �� ����������� ����.
                Temp = Temp->Left;
                // ������������� ������������ ����.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                //������ �� �p�������� ���� --> ����.
                A.V_stack(Temp);
            }
        }
        else //������ - ���p���.
            if (Temp->Right == NULL) //����������� �p���� ����.
            {
                //����p��p������ ����� ��� ������������ ����.
                Temp->Right = new (Uzel);
                // ��������� ��������� �� ����������� ����.
                Temp = Temp->Right;
                //������������� ������������ ����.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                // ������� ��������� "����p�������" �����.
                A.Udalenie(&Ukazatel);
                Temp = Ukazatel;
            }
            else   //���� �p���� ����.
            { //����p��p������ ����� ��� ������������ ����.
                Temp->Left = new (Uzel);
                // ��������� ��������� �� ����������� ����.
                Temp = Temp->Left;
                // ������������� ������������ ����.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                // ������� ��������� "����p�������" �����.
                A.Udalenie(&Ukazatel);
                Temp = Ukazatel;
            }
    } //����� for.
    cout << "\n����p������ ����� ��p���-��p����...\n";
    A.PrintTree(A.GetTree()->Right, 0);
    cout << "��p�� ���� ��p����, ���������� � ��������� ��p��...\n";
    A.Print_Tree_Back(A.GetTree()->Right, 0);
    cout << endl;
    cout << "------------------------------------------ \n";
    cout << "��p�� ���� ��p����, ���������� � �p�������� ��p��...\n";
    A.Print_Tree_Left(A.GetTree()->Right, 0);
    cout << endl;
    cout << "------------------------------------------ \n";
    cout << "��p�� ���� ��p����, ���������� � ����������� ��p��...\n";
    A.Print_Tree_End(A.GetTree()->Right, 0);

    cout << "\n";
    system("PAUSE");
}



